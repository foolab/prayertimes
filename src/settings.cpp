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

#include "settings.h"
#include <QStandardPaths>
#include <QCoreApplication>
#include <QDir>
#include "prayertimes.hpp"

#define CONF_FILE_PATH QString("%1%2%3%2%3.conf") \
  .arg(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)) \
  .arg(QDir::separator()) \
  .arg(QCoreApplication::instance()->applicationName())

#define DEFAULT_LONGITUDE               qreal(31.233333)
#define DEFAULT_LATITUDE                qreal(30.05)
#define DEFAULT_ALTITUDE                qreal(29.0)
#define DEFAULT_LOCATION_NAME           "Cairo"
#define DEFAULT_CALCULATION_METHOD      int(prayertimes::Egypt)

Settings::Settings(QObject *parent) :
  QSettings(CONF_FILE_PATH, QSettings::IniFormat, parent) {

}

Settings::~Settings() {

}

qreal Settings::longitude() const {
  return value("location/longitude", DEFAULT_LONGITUDE).toReal();
}

void Settings::setLongitude(qreal longitude) {
  if (!qFuzzyCompare(Settings::longitude(), longitude)) {
    setValue("location/longitude", longitude);
    emit longitudeChanged();
  }
}

qreal Settings::latitude() const {
  return value("location/latitude", DEFAULT_LATITUDE).toReal();
}

void Settings::setLatitude(qreal latitude) {
  if (!qFuzzyCompare(Settings::latitude(), latitude)) {
    setValue("location/latitude", latitude);
    emit latitudeChanged();
  }
}

QString Settings::locationName() const {
  return value("location/name", DEFAULT_LOCATION_NAME).toString();
}

void Settings::setLocationName(const QString& locationName) {
  if (Settings::locationName() != locationName) {
    setValue("location/name", locationName);
    emit locationNameChanged();
  }
}

qreal Settings::altitude() const {
  return value("location/altitude", DEFAULT_ALTITUDE).toReal();
}

void Settings::setAltitude(qreal altitude) {
  if (!qFuzzyCompare(Settings::altitude(), altitude)) {
    setValue("location/altitude", altitude);
    emit altitudeChanged();
  }
}

int Settings::calculationMethod() const {
  return value("location/calculationMethod", DEFAULT_CALCULATION_METHOD).toInt();
}

void Settings::setCalculationMethod(int calculationMethod) {
  if (Settings::calculationMethod() != calculationMethod) {
    setValue("location/calculationMethod", calculationMethod);
    emit calculationMethodChanged();
  }
}
