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

  Q_PROPERTY(qreal longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged);
  Q_PROPERTY(qreal latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged);
  Q_PROPERTY(qreal altitude READ altitude WRITE setAltitude NOTIFY altitudeChanged);
  Q_PROPERTY(int calculationMethod READ calculationMethod WRITE setCalculationMethod NOTIFY calculationMethodChanged);

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

  qreal longitude() const;
  void setLongitude(qreal longitude);

  qreal latitude() const;
  void setLatitude(qreal latitude);

  qreal altitude() const;
  void setAltitude(qreal altitude);

  int calculationMethod() const;
  void setCalculationMethod(int calculationMethod);

  QDateTime fajrTime() const;
  QDateTime sunriseTime() const;
  QDateTime dhuhrTime() const;
  QDateTime asrTime() const;
  QDateTime maghribTime() const;
  QDateTime ishaTime() const;

  bool ishaIsNextDay() const;

public slots:
  void calculate();

signals:
  void longitudeChanged();
  void latitudeChanged();
  void altitudeChanged();
  void calculationMethodChanged();
  void prayerTimesChanged();

private:
  QDateTime get(int pos) const;

  QMap<int, double> m_times;

  qreal m_longitude;
  qreal m_latitude;
  qreal m_altitude;
  int m_calculationMethod;
};

#endif /* PRAYER_TIME_CALCULATOR_H */
