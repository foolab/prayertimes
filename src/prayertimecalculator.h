// -*-c++-*-

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

#ifndef PRAYER_TIME_CALCULATOR_H
#define PRAYER_TIME_CALCULATOR_H

#include <QObject>
#include <QDateTime>
#include <QMap>

class PrayerTimeCalculator : public QObject {
  Q_OBJECT
  Q_PROPERTY(QDateTime fajrTime READ fajrTime NOTIFY prayerTimesChanged);
  Q_PROPERTY(QDateTime sunriseTime READ sunriseTime NOTIFY prayerTimesChanged);
  Q_PROPERTY(QDateTime dhuhrTime READ dhuhrTime NOTIFY prayerTimesChanged);
  Q_PROPERTY(QDateTime asrTime READ asrTime NOTIFY prayerTimesChanged);
  Q_PROPERTY(QDateTime maghribTime READ maghribTime NOTIFY prayerTimesChanged);
  Q_PROPERTY(QDateTime ishaTime READ ishaTime NOTIFY prayerTimesChanged);
  Q_PROPERTY(bool ishaIsNextDay READ ishaIsNextDay NOTIFY prayerTimesChanged);
public:
  PrayerTimeCalculator(QObject *parent = 0);
  ~PrayerTimeCalculator();

  QDateTime fajrTime() const;
  QDateTime sunriseTime() const;
  QDateTime dhuhrTime() const;
  QDateTime asrTime() const;
  QDateTime maghribTime() const;
  QDateTime ishaTime() const;

  bool ishaIsNextDay() const;

public slots:
  void calculate(qreal longitude, qreal latitude, int altitude, int calculationMethod);

signals:
  void prayerTimesChanged();

private:
  QDateTime get(int pos) const;

  QMap<int, double> m_times;
};

#endif /* PRAYER_TIME_CALCULATOR_H */
