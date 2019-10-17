import QtQuick 2.11
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.3
import "."

Rectangle {
    id: panel
    property string receiving
    property string sending
    property string maturing
    property string bheight
    property string ver
    property string balance


    color: Style.navigation_background
    clip: true
    border.width: 1
    border.color: Style.accent_outgoing2
    radius: 10
    opacity: 0.9

    signal copyValueText(string value)

    ColumnLayout {
        anchors.fill: parent
        anchors.topMargin: 15
        anchors.leftMargin: 10
        anchors.rightMargin: 0
        anchors.bottomMargin: 15


        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true


            ColumnLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                spacing: 10



                SFLabel {
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.styleName: "Normal"
                    font.weight: Font.Normal
                    font.pixelSize: 16
                    opacity: 0.6
                    color: Style.accent_incoming
                    text: bheight;
                    elide: Text.ElideRight
                    copyMenuEnabled: true
                    onCopyText: panel.copyValueText(bheight)
                }

                SFText {
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 12
                    font.styleName: "Normal";
                    font.weight: Font.Bold
                    color: Style.content_main
                    opacity: 0.6
                    //% "BLOCK HEIGHT"
                    text: "BLOCK HEIGHT"
                }

            }

            ColumnLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                spacing: 10




                SFLabel {
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.styleName: "Normal"
                    font.weight: Font.Normal
                    font.pixelSize: 16
                    opacity: 0.6
                    color: Style.accent_incoming
                    text: balance;
                    elide: Text.ElideRight
                    copyMenuEnabled: true
                    onCopyText: panel.copyValueText(balance)
                }

                SFText {
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 12
                    font.styleName: "Normal";
                    font.weight: Font.Bold
                    color: Style.content_main
                    opacity: 0.6
                    //% "BALANCE"
                    text: "GRIMM BALANCE"
                }
            }


            ColumnLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                spacing: 10





                SFLabel {
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.styleName: "Normal"
                    font.weight: Font.Normal
                    font.pixelSize: 16
                    opacity: 0.6
                    color: Style.accent_incoming
                    text: receiving;
                    elide: Text.ElideRight
                    copyMenuEnabled: true
                    onCopyText: panel.copyValueText(receiving)
                }

                SFText {
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 12
                    font.styleName: "Normal";
                    font.weight: Font.Bold
                    color: Style.content_main
                    opacity: 0.6
                    //% "RECEIVING"
                    text: "RECEIVING COINS"
                }
            }

            ColumnLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                spacing: 10





                SFLabel {
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.styleName: "Normal"
                    font.weight: Font.Normal
                    font.pixelSize: 16
                    opacity: 0.9
                    color: Style.accent_outgoing
                    text: sending;
                    elide: Text.ElideRight
                    copyMenuEnabled: true
                    onCopyText: panel.copyValueText(sending)
                }

                SFText {
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 12
                    font.styleName: "Normal";
                    font.weight: Font.Bold
                    color: Style.content_main
                    opacity: 0.6
                    //% "SENDING"
                    text: "SENDING COINS"
                }
            }

            ColumnLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                spacing: 10




                SFLabel {
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.styleName: "Normal"
                    font.weight: Font.Normal
                    font.pixelSize: 16
                    opacity: 0.9
                    color: Style.accent_outgoing
                    text: maturing;
                    elide: Text.ElideRight
                    copyMenuEnabled: true
                    onCopyText: panel.copyValueText(maturing)
                }

                SFText {
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 12
                    font.styleName: "Normal";
                    font.weight: Font.Bold
                    color: Style.content_main
                    opacity: 0.6
                    //% "MATURING"
                    text: "LOCKED COINS"
                }

            }

            ColumnLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                spacing: 10
                visible: sviewModel.localNodeRun

                SFLabel {
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
                Layout.preferredHeight: 18
                Layout.preferredWidth: 30
                verticalAlignment: Text.AlignVCenter
                font.styleName: "Normal"
                font.weight: Font.Normal
                font.pixelSize: 12
                opacity: 0.6
                    color: Style.accent_incoming
                    text: "FULL NODE"
                    elide: Text.ElideRight
                    copyMenuEnabled: true

                }

                StatusBar2 {
                    Layout.preferredHeight: 14
                    Layout.preferredWidth: 50
                    opacity: 0.8
                    id: status_bar_dash
                    model: statusbarModel
                    Layout.alignment: Qt.AlignHCenter
                }


            }

            ColumnLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                spacing: 10
                visible: !sviewModel.localNodeRun



                SFLabel {
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
                Layout.preferredHeight: 18

                verticalAlignment: Text.AlignVCenter
                font.styleName: "Normal"
                font.weight: Font.Normal
                font.pixelSize: 12
                opacity: 0.9
                color: Style.accent_outgoing
                    text: "REMOTE NODE"
                    elide: Text.ElideRight
                    copyMenuEnabled: true
                    
                }
                StatusBar2 {
                    Layout.preferredHeight: 14
                    Layout.preferredWidth: 50
                    opacity: 0.8
                    Layout.alignment: Qt.AlignHCenter
                    id: status_bar_dash2
                    model: statusbarModel
                }

            }


        }

    }
}
