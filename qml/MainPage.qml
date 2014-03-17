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
        Component.onCompleted: calculate(settings.longitude, settings.latitude, settings.altitude, settings.calculationMethod)
    }

    property list<QtObject> prayerModel: [
        QtObject {
            property variant stamp: calculator.fajrTime
            property string name: qsTr("Fajr")
            property bool nextDay
        },
        QtObject {
            property variant stamp: calculator.sunriseTime
            property string name: qsTr("Sunrise")
            property bool nextDay
        },
        QtObject {
            property variant stamp: calculator.dhuhrTime
            property string name: qsTr("Dhuhr")
            property bool nextDay
        },
        QtObject {
            property variant stamp: calculator.asrTime
            property string name: qsTr("Asr")
            property bool nextDay
        },
        QtObject {
            property variant stamp: calculator.maghribTime
            property string name: qsTr("Maghrib")
            property bool nextDay
        },
        QtObject {
            property variant stamp: calculator.ishaTime
            property string name: qsTr("Isha")
            property bool nextDay
        }
    ]

    SilicaListView {
        id: view
        anchors.fill: parent

        PullDownMenu {
            MenuItem { text: qsTr("About"); onClicked: Qt.resolvedUrl("AboutPage.qml") }
            MenuItem { text: qsTr("Location"); onClicked: Qt.resolvedUrl("LocationPage.qml") }
            MenuItem { text: qsTr("Settings"); onClicked: Qt.resolvedUrl("SettingsPage.qml") }
        }

        header: PageHeader {
            width: parent.width
            title: settings.locationName
        }

        model: prayerModel

        delegate: Item {
            width: view.width
            height: Theme.itemSizeSmall

            Label {
                height: Theme.itemSizeSmall
                anchors {
                    left: parent.left
                    leftMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingSmall
                text: name
            }

            Label {
                height: Theme.itemSizeSmall
                anchors {
                    right: parent.right
                    rightMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingLarge
                horizontalAlignment: Text.AlignRight
                text: "%1".arg(Qt.formatDateTime(stamp, "hh:mm"))
            }
        }

        footer: Label {
            x: Theme.paddingLarge
            width: parent.width
            color: Theme.highlightColor
            text: qsTr("* Next day prayer")
        }
    }
}
