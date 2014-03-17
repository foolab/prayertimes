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

import QtQuick 2.1
import Sailfish.Silica 1.0
import Harbour.Prayer 1.0

Page {

    PrayerTimeCalculator {
        id: calculator
        Component.onCompleted: calculate(settings.longitude, settings.latitude, settings.calculationMethod)
    }

    SilicaFlickable {
        anchors.fill: parent

        PullDownMenu {
            MenuItem { text: qsTr("About"); onClicked: Qt.resolvedUrl("AboutPage.qml") }
            MenuItem { text: qsTr("Location"); onClicked: Qt.resolvedUrl("LocationPage.qml") }
            MenuItem { text: qsTr("Settings"); onClicked: Qt.resolvedUrl("SettingsPage.qml") }
        }

        Column {
            width: parent.width

            PageHeader {
                width: parent.width
                title: settings.locationName
            }

            Row {
                width: parent.width

                Label {
                    width: parent.width / 2
                    text: qsTr("Fajr")
                }

                Label {
                    width: parent.width / 2
                    text: Qt.formatDateTime(calculator.fajrTime, "hh:mm")
                }
            }

            Row {
                width: parent.width
                Label {
                    width: parent.width / 2
                    text: qsTr("Sunrise")
                }

                Label {
                    width: parent.width / 2
                    text: Qt.formatDateTime(calculator.sunriseTime, "hh:mm")
                }
            }

            Row {
                width: parent.width
                Label {
                    width: parent.width / 2
                    text: qsTr("Dhuhr")
                }

                Label {
                    width: parent.width / 2
                    text: Qt.formatDateTime(calculator.dhuhrTime, "hh:mm")
                }
            }

            Row {
                width: parent.width
                Label {
                    width: parent.width / 2
                    text: qsTr("Asr")
                }

                Label {
                    width: parent.width / 2
                    text: Qt.formatDateTime(calculator.asrTime, "hh:mm")
                }
            }

            Row {
                width: parent.width
                Label {
                    width: parent.width / 2
                    text: qsTr("Maghrib")
                }

                Label {
                    width: parent.width / 2
                    text: Qt.formatDateTime(calculator.maghribTime, "hh:mm")
                }
            }

            Row {
                width: parent.width
                Label {
                    width: parent.width / 2
                    text: qsTr("Isha")
                }

                Label {
                    width: parent.width / 2
                    text: Qt.formatDateTime(calculator.ishaTime, "hh:mm")
                }
            }
        }
    }
}