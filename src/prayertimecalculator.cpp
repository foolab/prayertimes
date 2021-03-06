/*
 * This file is part of harbour-prayer.
 *
 * harbour-prayer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "prayertimecalculator.h"
#include "prayertimes.hpp"
#include <QDate>
#include <QDebug>

#define FAJR_POSITION         prayertimes::Fajr
#define SUNRISE_POSITION      prayertimes::Sunrise
#define DHUHR_POSITION        prayertimes::Dhuhr
#define ASR_POSITION          prayertimes::Asr
#define MAGHRIB_POSITION      prayertimes::Maghrib
#define ISHA_POSITION         prayertimes::Isha

PrayerTimeCalculator::PrayerTimeCalculator(QObject *parent) :
  QObject(parent),
  m_longitude(-1),
  m_latitude(-1),
  m_altitude(-1),
  m_calculationMethod(-1) {

}

PrayerTimeCalculator::~PrayerTimeCalculator() {

}

qreal PrayerTimeCalculator::longitude() const {
  return m_longitude;
}

void PrayerTimeCalculator::setLongitude(qreal longitude) {
  if (!qFuzzyCompare(m_longitude, longitude)) {
    m_longitude = longitude;
    emit longitudeChanged();
    calculate();
  }
}

qreal PrayerTimeCalculator::latitude() const {
  return m_latitude;
}

void PrayerTimeCalculator::setLatitude(qreal latitude) {
  if (!qFuzzyCompare(m_latitude, latitude)) {
    m_latitude = latitude;
    emit latitudeChanged();
    calculate();
  }
}

qreal PrayerTimeCalculator::altitude() const {
  return m_altitude;
}

void PrayerTimeCalculator::setAltitude(qreal altitude) {
  if (!qFuzzyCompare(m_altitude, altitude)) {
    m_altitude = altitude;
    emit altitudeChanged();
    calculate();
  }
}

int PrayerTimeCalculator::calculationMethod() const {
  return m_calculationMethod;
}

void PrayerTimeCalculator::setCalculationMethod(int calculationMethod) {
  if (m_calculationMethod != calculationMethod) {
    m_calculationMethod = calculationMethod;
    emit calculationMethodChanged();
    calculate();
  }
}

void PrayerTimeCalculator::calculate() {
  if (m_longitude < 0 || m_latitude < 0 || m_altitude < 0 || m_calculationMethod < 0) {
    return;
  }

  prayertimes::PrayerTimes times;
  time_t date = time(NULL);
  qreal timezone = prayertimes::PrayerTimes::get_timezone(date);
  qDebug() << timezone;
  double output[prayertimes::TimesCount];

  times.set_calc_method(static_cast<prayertimes::CalculationMethod>(m_calculationMethod));
  times.get_prayer_times(date, m_latitude, m_longitude, m_altitude, timezone, output);
  m_times.clear();

  QList<int> positions;
  positions << FAJR_POSITION << SUNRISE_POSITION << DHUHR_POSITION << ASR_POSITION << MAGHRIB_POSITION << ISHA_POSITION;
  for (int x = 0; x < positions.size(); x++) {
    m_times.insert(positions[x], output[positions[x]]);
  }

  emit prayerTimesChanged();
}

QDateTime PrayerTimeCalculator::get(int pos) const {
  if (!m_times.contains(pos)) {
    return QDateTime();
  }

  double time = m_times[pos];

  bool addDays = false;
  int seconds = time;
  int hours = seconds / 3600;
  seconds %= 3600;
  int minutes = seconds / 60;
  seconds %= 60;

  if (hours >= 24) {
    hours -= 24;
    addDays = true;
  }

  QTime t = QTime(hours, minutes, seconds);
  QDateTime dt = QDateTime::currentDateTime();
  if (addDays) {
    dt.addDays(1);
  }

  dt.setTime(t);

  qDebug() << hours << minutes << seconds << addDays;

  return dt;
}

QDateTime PrayerTimeCalculator::fajrTime() const {
  return get(FAJR_POSITION);
}

QDateTime PrayerTimeCalculator::sunriseTime() const {
  return get(SUNRISE_POSITION);
}

QDateTime PrayerTimeCalculator::dhuhrTime() const {
  return get(DHUHR_POSITION);
}

QDateTime PrayerTimeCalculator::asrTime() const {
  return get(ASR_POSITION);
}

QDateTime PrayerTimeCalculator::maghribTime() const {
  return get(MAGHRIB_POSITION);
}

QDateTime PrayerTimeCalculator::ishaTime() const {
  return get(ISHA_POSITION);
}

bool PrayerTimeCalculator::ishaIsNextDay() const {
  if (!m_times.contains(ISHA_POSITION)) {
    return false;
  }

  double time = m_times[ISHA_POSITION];
  return time >= 86400;
}
