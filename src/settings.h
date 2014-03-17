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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Settings : public QSettings {
  Q_OBJECT
  Q_PROPERTY(qreal longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged);
  Q_PROPERTY(qreal latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged);
  Q_PROPERTY(QString locationName READ locationName WRITE setLocationName NOTIFY locationNameChanged);
  Q_PROPERTY(int altitude READ altitude WRITE setAltitude NOTIFY altitudeChanged);
  Q_PROPERTY(int calculationMethod READ calculationMethod WRITE setCalculationMethod NOTIFY calculationMethodChanged);

public:
  Settings(QObject *parent = 0);
  ~Settings();

  qreal longitude() const;
  void setLongitude(qreal longitude);

  qreal latitude() const;
  void setLatitude(qreal latitude);

  QString locationName() const;
  void setLocationName(const QString& locationName);

  int altitude() const;
  void setAltitude(int altitude);

  int calculationMethod() const;
  void setCalculationMethod(int calculationMethod);

signals:
  void longitudeChanged();
  void latitudeChanged();
  void locationNameChanged();
  void altitudeChanged();
  void calculationMethodChanged();
};

#endif /* SETTINGS_H */
