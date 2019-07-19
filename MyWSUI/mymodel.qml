import QtQuick 2.5

Item {
    property bool isempty: true
    property alias model: dataModel

    ListModel {
        id: dataModel
    }
}
