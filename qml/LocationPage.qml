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

Dialog {
    canAccept: name.text != "" && longitude.text >= 0 && latitude.text >= 0 && altitude.text >= 0

    Column {
        width: parent.width

        DialogHeader {
            width: parent.width
            acceptText: qsTr("Change city")
        }

        Item {
            width: parent.width
            height: Theme.itemSizeMedium

            Label {
                height: Theme.itemSizeMedium
                anchors {
                    left: parent.left
                    leftMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingSmall
                text: qsTr("City name:")
            }

            TextField {
                id: name
                height: Theme.itemSizeMedium
                anchors {
                    right: parent.right
                    rightMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingLarge
                horizontalAlignment: Text.AlignHCenter
                text: settings.locationName
            }
        }

        Item {
            width: parent.width
            height: Theme.itemSizeMedium

            Label {
                height: Theme.itemSizeMedium
                anchors {
                    left: parent.left
                    leftMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingSmall
                text: qsTr("Longitude:")
            }

            TextField {
                id: longitude
                height: Theme.itemSizeMedium
                anchors {
                    right: parent.right
                    rightMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingLarge
                horizontalAlignment: Text.AlignHCenter
                inputMethodHints: Qt.ImhDigitsOnly
                text: settings.longitude
            }
        }

        Item {
            width: parent.width
            height: Theme.itemSizeMedium

            Label {
                height: Theme.itemSizeMedium
                anchors {
                    left: parent.left
                    leftMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingSmall
                text: qsTr("Latitude:")
            }

            TextField {
                id: latitude
                height: Theme.itemSizeMedium
                anchors {
                    right: parent.right
                    rightMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingLarge
                horizontalAlignment: Text.AlignHCenter
                inputMethodHints: Qt.ImhDigitsOnly
                text: settings.latitude
            }
        }

        Item {
            width: parent.width
            height: Theme.itemSizeMedium

            Label {
                height: Theme.itemSizeMedium
                anchors {
                    left: parent.left
                    leftMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingSmall
                text: qsTr("Altitude:")
            }

            TextField {
                id: altitude
                height: Theme.itemSizeMedium
                anchors {
                    right: parent.right
                    rightMargin: Theme.paddingLarge
                    top: parent.top
                }

                width: (parent.width / 2) - Theme.paddingLarge
                horizontalAlignment: Text.AlignHCenter
                inputMethodHints: Qt.ImhDigitsOnly
                text: settings.altitude
            }
        }

        ComboBox {
            id: calculationMethod
            menu: ContextMenu {
                MenuItem { text: qsTr("Muslim World League") }
                MenuItem { text: qsTr("Islamic Society of North America") }
                MenuItem { text: qsTr("Egyptian General Authority of Survey") }
                MenuItem { text: qsTr("Umm Al-Qura University, Makkah") }
                MenuItem { text: qsTr("University of Islamic Sciences, Karachi") }
                MenuItem { text: qsTr("Shia Ithna-Ashari, Leva Institute, Qum") }
                MenuItem { text: qsTr("Institute of Geophysics, University of Tehran") }
            }

            label: qsTr("Calculation method")
            currentIndex: settings.calculationMethod
        }
    }

    onAccepted: {
        settings.locationName = name.text
        settings.longitude = longitude.text
        settings.latitude = latitude.text
        settings.altitude = altitude.text
        settings.calculationMethod = calculationMethod.currentIndex
    }
}
