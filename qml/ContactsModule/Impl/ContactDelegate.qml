import QtQuick 2.0
import StyleModule 1.0
import ContactsModule.Base 1.0
import ResourceProvider 1.0

Rectangle {
    id: root

    color: Style.backgroundColor
    opacity: _delegateArea.pressed ? Style.secondaryOpacity
                                   : Style.emphasisOpacity

    ImageBubble {
        id: _image
        anchors.left: root.left
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter

        bubbleRadius: root.height - Style.defaultOffset
        imageSource: ResourceProvider.contacts.defaultContactIcon
    }

    Column {
        anchors.left: _image.right
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter

        Row {
            spacing: Style.smallSpacing
            BaseText {
                text: name
            }
            BaseText {
                text: surname
            }
        }

        BaseText {
            text: phoneNumber
            color: Style.primaryColor
        }
    }

    MouseArea {
        id: _delegateArea
        anchors.fill: root
    }
}
