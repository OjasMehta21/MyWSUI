import QtQuick 2.7
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3
import QtQuick.Extras 1.4
import QtGraphicalEffects 1.0
import Core 1.0
import "."
ApplicationWindow {
    id: workspace
    visible: true
    width: 1000
    height: 800
    title: qsTr("MyWSUI 3.0")
    MessageDialog {
        id: aboutDialog
        icon: StandardIcon.Information
        title: "About"
        text: "Qt Quick Controls Gallery"
        informativeText: "This example demonstrates most of the available Qt Quick Controls."
    }


    Action {
        id: copyAction
        text: "&Copy"
        shortcut: StandardKey.Copy
        icon.name: "edit-copy"
        enabled: (!!activeFocusItem && !!activeFocusItem["copy"])
        onTriggered: activeFocusItem.copy()
    }

    Action {
        id: cutAction
        text: "&Cut"
        shortcut: StandardKey.Cut
        icon.name: "edit-cut"
        enabled: (!!activeFocusItem && !!activeFocusItem["cut"])
        onTriggered: activeFocusItem.cut()
    }

    Action {
        id: pasteAction
        text: "&Paste"
        shortcut: StandardKey.Paste
        icon.name: "edit-paste"
        enabled: (!!activeFocusItem && !!activeFocusItem["paste"])
        onTriggered: activeFocusItem.paste()
    }

    header: ToolBar {
        RowLayout {
            //anchors.fill: parent
            spacing: 0
            ToolButton {
                icon.source: "icons/file_yellow_empty.png"
                icon.color: "transparent"

            }

            ToolButton {
                icon.source: "icons/directory_open.png"
                icon.color: "transparent"
            }
            ToolButton {
                icon.source: "icons/floppy_save.png"
                icon.color: "transparent"
            }
            ToolButton {
                icon.source: "icons/scissors.png"
                icon.color: "transparent"
            }

            ToolButton {
                icon.source: "icons/copy.png"
                icon.color: "transparent"
            }

            ToolButton {
                icon.source: "icons/paste.png"
                icon.color: "transparent"
            }
            ToolButton {
                icon.source: "icons/undo_blue.png"
                icon.color: "transparent"
            }
            ToolButton {
                icon.source: "icons/redo_blue.png"
                icon.color: "transparent"
            }
            ToolButton {
                icon.source: "icons/pencil_green.png"
                icon.color: "transparent"
            }
            ToolButton {
                icon.source: "icons/info.png"
                icon.color: "transparent"
            }
            ToolButton {
                icon.source: "icons/magnifier.png"
                icon.color: "transparent"
            }
            ToolButton {
                icon.source: "icons/plus_green.png"
                icon.color: "transparent"
            }
            ToolButton {
                icon.source: "icons/minus_red.png"
                icon.color: "transparent"
            }
        }
    }
    footer: ToolBar {
        RowLayout {
            spacing:0

                        ToolButton {
                            icon.source: "icons/ellipse_green.png"
                            icon.color: "transparent"
                        }
                        ToolButton {
                            icon.source: "icons/ellipse_blue.png"
                            icon.color: "transparent"
                        }

                        ToolButton {
                            icon.source: "icons/ellipse_yellow.png"
                           icon.color: "transparent"
                        }
        }
    }

    menuBar: MenuBar {
        Menu {
            title: "&File"
            Menu {
                title: "New"
                MenuItem {
                    text: "Recipe"
                    onTriggered: openRecipeEditor();
                }
                MenuItem {
                    text: "Batch"

                    onTriggered: something.open();
                }
                MenuItem {
                    text: "Gallery Template"
                    onTriggered: inProgress();
                }
                MenuItem {
                    text: "Golder Wafer"
                    onTriggered: inProgress();
                }
            }
            Menu {
                title: "Open"
                MenuItem {
                    //to open 3d wafermap
                    text: "Wafer"
                    onTriggered: open3dmap();
                }
                MenuItem {
                    text: "Recipe"
                    onTriggered: inProgress();
                }
                MenuItem {
                    text: "Batch"
                    onTriggered: inProgress();
                }
                MenuItem {
                    text: "Gallery Template"
                    onTriggered: inProgress();
                }
            }

            MenuItem {
                text: "Import From Recipe"
                onTriggered: inProgress();
            }
            MenuItem {
                text: "Save"
                onTriggered: inProgress();
            }
            MenuItem {
                text: "Save As"
                onTriggered: inProgress();
            }
            MenuItem {
                text: "Export Image"
                enabled: false
                onTriggered: inProgress();
            }
            MenuItem {
                text: "Export Profile"
                enabled: false
                onTriggered: inProgress();
            }
            MenuItem {
                text: "Print"
                onTriggered: inProgress();
            }
            MenuItem {
                text: "&Exit"

                onTriggered: Qt.quit()
            }
        }
//        Menu {
//            title: "&Edit"
//            //visible: tabView.currentIndex == 2
//            MenuItem { action: cutAction }
//            MenuItem { action: copyAction }
//            MenuItem { action: pasteAction }
//        }
//        Menu {
//            title: "&Help"
//            MenuItem {
//                text: "About..."
//                onTriggered: aboutDialog.open()
//            }
//        }
        Menu {
            title: "View"
            MenuItem {
                text: "Messages"
                onTriggered: openRecipeEditor();
            }
            MenuItem {
                text: "Reports"

                onTriggered: inProgress();
            }
            MenuItem {
                text: "Set Color Map..."
                onTriggered: inProgress();
            }
            MenuItem {
                text: "Set Color Height Range..."
                onTriggered: inProgress();
            }
        }

        Menu {
            title: "Data"
            MenuItem {
                text: "Apply Recipe..."
                onTriggered: openRecipeEditor();
            }
            MenuItem {
                text: "Subtract Wafer..."

                onTriggered: inProgress();
            }
            MenuItem {
                text: "Calculate Radial Profiles..."
                onTriggered: inProgress();
            }
            MenuItem {
                text: "Show X Profile..."
                onTriggered: inProgress();
            }
            MenuItem {
                text: "Show Y Profile..."
                onTriggered: inProgress();
            }
            MenuItem {
                text: "Show X Profile..."
                enabled: false
                onTriggered: inProgress();
            }
        }
        Menu{
            title: "Database"
            MenuItem{
                text:"Edit Database"
                onTriggered: inProgress();
            }
        }
        Menu{
            title: "Script"
            MenuItem{
                text:"Edit Script"
                onTriggered: inProgress();
            }
            MenuItem{
                text:"Open Console"
                onTriggered: inProgress();
            }
        }
        Menu{
            title: "Window"
            MenuItem{
                text:"Messages"
                onTriggered: inProgress();
            }
        }
        Menu{
            title: "Help"
            MenuItem{
                text:"About"
                onTriggered: inProgress();
            }
        }



    }
    Dialog {
        visible: false
        title: "Blue sky dialog"
        id: something
        contentItem: Rectangle {
            //color: "lightskyblue"
            implicitWidth: 400
            implicitHeight: 100
            Text {
                text: "This feature is yet to implemented."
                //color: "navy"
                anchors.centerIn: parent
            }
        }
    }
//    Button {
//            anchors.centerIn: parent
//            text: qsTr("Click me")

//            onClicked: {
//                var component = Qt.createComponent("qrc:/recipeEditor.qml");
//                var window    = component.createObject("workspace");
//                window.show();
//            }
//     }
    function openRecipeEditor(){
        var component = Qt.createComponent("qrc:/RecipeEditor.qml");
        var window    = component.createObject("workspace");
        window.show();
    }
    function inProgress(){
        something.open();
    }
    function open3dmap(){
        var component = Qt.createComponent("qrc:/ThreeD_Surface.qml");
        var window    = component.createObject("workspace");
        window.show();
    }



}
