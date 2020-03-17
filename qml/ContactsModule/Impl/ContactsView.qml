import QtQuick 2.0
import ContactsModule 1.0

ListView {
    id: root

    model: ContactsModel {

    }

    delegate: ContactDelegate {
        width: root.width
        height: 70
    }

    Component.onCompleted: {
        model.startManualUpdate();
    }
}
