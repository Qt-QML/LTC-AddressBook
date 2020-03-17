pragma Singleton
import QtQuick 2.0

Item
{
    property alias contacts: _contactsResources
    QtObject {
        id: _contactsResources
        readonly property string defaultContactIcon: "qrc:/qml/resources/default-contact-icon.svg"
    }
}
