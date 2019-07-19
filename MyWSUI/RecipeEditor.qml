import QtQuick 2.7
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Extras 1.4
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.2
import QtDataVisualization 1.0
import Core 1.0

ApplicationWindow {
    id: recipeEditor
    width: 1050
    height: 800
    visible:  true
    title: qsTr("Recipe Editor")
    header:TabBar {
        id: myTabBar

        TabButton {
            text: qsTr("Basic")
        }
        TabButton {
            text: qsTr("Care Areas && Site Masks")
        }
        TabButton {
            text: qsTr("Show As Text")
        }
        TabButton {
            text: qsTr("Define Regions")
        }
        TabButton {
            text: qsTr("Select Sites")
        }
    }

    StackLayout {
        currentIndex: myTabBar.currentIndex
        anchors.fill: parent
        Item{
            id:homeTab
        Rectangle {
            anchors.fill: parent
            color: "#212121"
            GridLayout {
                id: gridLayout
                anchors.fill: parent
                columns:3

                ColumnLayout {
                    id: leftColumnLayout
                    //Layout.fillHeight: true
                    Layout.preferredHeight: parent.height
                    Component.onCompleted: {console.log(parent.height)}
                    width: parent.width/6
                    Rectangle{
                        Text {
                            id: name
                            text: qsTr("Site Layout")
                        }
                        Layout.preferredHeight: leftColumnLayout.height/2
                        Layout.preferredWidth: parent.width
                        color: "grey"
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                    }
                    ColumnLayout{
                        Layout.alignment: Qt.AlignBottom
                        spacing: 0
                        Layout.preferredHeight: leftColumnLayout.height/4
                        Button {
                            id: left1
                            text: "Add Polar Mask..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.alignment: Qt.AlignBottom
                            visible: true
                            opacity: 1
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            onClicked: {inProgress();
                            }
                            //onClicked: {fileDialog.visible=true; myCanvas.requestPaint();}
                        }
                        Button {
                            id: left2
                            text: "Add Cartesian Mask..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.alignment: Qt.AlignBottom
                            visible: true
                            opacity: 1
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            onClicked: {inProgress();
                            }
                            //onClicked: {fileDialog.visible=true; myCanvas.requestPaint();}
                        }
                        Button {
                            id: left3
                            text: "Edit Mask..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.alignment: Qt.AlignBottom
                            visible: true
                            opacity: 1
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            onClicked: {inProgress();
                            }
                            //onClicked: {fileDialog.visible=true; myCanvas.requestPaint();}
                        }
                        Button {
                            id: left4
                            text: "Delete Mask"
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.alignment: Qt.AlignBottom
                            visible: true
                            opacity: 1
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            onClicked: {inProgress();
                            }
                            //onClicked: {fileDialog.visible=true; myCanvas.requestPaint();}
                        }
                        CheckBox{
                            text: "Show Masks"
                            checked: true;
                        }
                    }



                }
                Rectangle{
                    id: rectangle
                    width: 4*(parent.width/6)
                    Layout.minimumWidth: 610
                    color: "#424242"
                    Layout.fillHeight: true


                    Canvas {
                        id: myCanvas
                        property var radius: 150
                        width: 596
                        height: 596
                        //anchors.horizontalCenter: parent.Center
                        x:7
                        y:5
//                        onPaint: {
//                            // unloadWafer();
//                        }

                    }
                    Component.onCompleted: {
                        unloadWafer();
                    }
                }

                ColumnLayout {
                    id: columnLayout
                    y: 0
                    height: parent.height
                    spacing: 15
                    Layout.alignment: Qt.AlignRight | Qt.AlignTop

                    Layout.fillHeight: true
                    width: parent.width/6

                    //scale: 0.01
                    ColumnLayout {
                        id: column1
                        Layout.fillWidth: true;
                        Layout.preferredHeight: columnLayout.height/10
                        Layout.alignment: Qt.AlignTop
                        spacing: 0
                        Button {
                            id: loadWaferRE
                            text: "Load Wafer"

                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            visible: true
                            opacity: 1
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            onClicked: {fileDialog.open();
                            }
                            //onClicked: {fileDialog.visible=true; myCanvas.requestPaint();}
                        }
                        Button {
                            id: unloadWaferRE
                            text: "Unload Wafer"
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            Layout.alignment: Qt.AlignTop
                            visible: true
                            opacity: 1
                            onClicked: {unloadWafer();}
                        }

                    }

                    ColumnLayout {
                        id: columnRight
                        Layout.preferredHeight: columnLayout.height/10
                        Layout.fillWidth: true;
                        spacing: 0
                        RadioButton {
                            checked: true
                            text: qsTr("Front side")
                        }
                        RadioButton {
                            text: qsTr("Back side")
                        }

                        RadioButton {
                            text: qsTr("Shape")
                        }

                        RadioButton {
                            text: qsTr("Thickness")
                        }
                    }

                    ColumnLayout {
                        id: column

                        Layout.preferredHeight: 4*columnLayout.height/10
                        Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                        width: parent.width
                        spacing: 0
                        Button {
                            text: "Select Golden..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10

                            visible: true
                            opacity: 1
                            onClicked: {inProgress();}
                        }

                        Button {
                            text: "Edge Exclusion..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10

                            visible: true
                            opacity: 1
                            onClicked: {inProgress();}
                        }

                        Button {
                            text: "Site Array..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            visible: true
                            opacity: 1
                            onClicked: {inProgress();}
                        }

                        Button {
                            text: "Polar Sites..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            visible: true
                            opacity: 1
                            onClicked: {inProgress();}
                        }

                        Button {
                            text: "Profiles..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            visible: true
                            opacity: 1
                            onClicked: {inProgress();}
                        }

                        Button {
                            text: "Categories..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            visible: true
                            opacity: 1
                            onClicked: {inProgress();}
                        }

                        Button {
                            text: "Output..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            visible: true
                            opacity: 1
                            onClicked: {inProgress();}
                        }

                        Button {
                            text: "Extra Analyses..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            visible: true
                            opacity: 1
                            onClicked: {inProgress();}
                        }

                        Button {
                            text: "SECS/GEM Analyses..."
                            Layout.fillWidth: true
                            wheelEnabled: true
                            //flat: true
                            highlighted: true
                            Layout.rightMargin: 10
                            Layout.leftMargin: 10
                            visible: true
                            opacity: 1
                            onClicked: {inProgress();}
                        }
                    }



                }


                //        GroupBox {
                //            id: groupBoxRE
                //            width: 150
                //            Layout.fillHeight: true
                //            ///Layout.alignment: Qt.AlignRight
                //            ColumnLayout {
                //                id: columnLayout
                //                anchors.fill: parent
                //                Button {
                //                    id: loadWaferRE
                //                    text: "Load Wafer"

                //                    wheelEnabled: true
                //                    flat: true
                //                    highlighted: true
                //                    //Layout.alignment: Qt.AlignTop
                //                    visible: true
                //                    opacity: 1
                //                    onClicked: {fileDialog.open();//loadWafer();
                //                    }
                //                    //onClicked: {fileDialog.visible=true; myCanvas.requestPaint();}
                //                }
                //                Button {
                //                    id: unloadWaferRE
                //                    text: "Unload Wafer"

                //                    wheelEnabled: true
                //                    flat: true
                //                    highlighted: true
                //                    //Layout.alignment: Qt.AlignVCenter
                //                    visible: true
                //                    opacity: 1
                //                    onClicked: {unloadWafer();}
                //                }

                //            }
                //        }



            }

        }
        }
        Item {
            id: discoverTab
        }
        Item {
            id: activityTab
        }
        Item {
            id: defineRegion
        }
        Item {
            id: selectSites
        }
    }


    FileDialog {
        id: fileDialog
        //            title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            var cpath = fileDialog.fileUrl.toLocaleString()

            cpath = cpath.replace(/^(file:\/{3})/,"");

            var cleanPath = decodeURIComponent(cpath);
            console.log(cleanPath)
            myObject.show(cleanPath);

        }
        onRejected: {
            console.log("Canceled")

        }
    }

    MyData {
        id: myObject
        ///var plotZ;
        onDataLoaded: {loadWafer();}
    }

    function loadWafer(){

//        var plotZ = [1, 2, 3, 4];
//        console.log(typeof(plotZ));
//         plotZ= Array.from(myObject.plotZ);
//        for(var i=0; i<10; i++)console.log(plotZ[i]);
        var ctx = myCanvas.getContext("2d");
        ctx.reset();
        var dataLen = myObject.plotZ.length;
        console.log(typeof(plotZ));
        var arr = ctx.getImageData(0, 0, myCanvas.width, myCanvas.height);
        var arrlen = arr.data.length;
        console.log('dl',dataLen);
        console.log('al', arrlen);
        var currentZ = 1;
        var data = arr.data;
        var startTime = new Date().getTime();
        for(var i = 0, j = 0; i<arrlen && j<dataLen; i+=4, j++){
            currentZ = myObject.plotZ[j];
            if(currentZ!=255){
                data[i] = 255;
                data[i+1] = 255 - currentZ
                data[i+2] = 255 - currentZ
                data[i+3] = 255;
            }
        }
        var endTime = new Date().getTime();
        ctx.imageSmoothingEnabled = false;

        ctx.drawImage(arr,0,0);
        myCanvas.requestPaint();

        console.log(endTime-startTime);
    }
    function unloadWafer(){
        var ctx = myCanvas.getContext("2d");
        console.log('unLoaded');
        ctx.clearRect(0,0,myCanvas.height, myCanvas.width);
        var centreX = myCanvas.width / 2;
        var centreY = myCanvas.height / 2;
        ctx.moveTo(myCanvas.width, myCanvas.height);
        ctx.beginPath();
        ctx.lineWidth = 3;
        ctx.arc(centreX, centreY, myCanvas.width/2-5, 0, Math.PI * 2, true);
        ctx.strokeStyle = 'yellow';
        ctx.stroke();
        ctx.lineWidth = 1;
        ctx.arc(centreX, centreY, myCanvas.width/2-20, 0, Math.PI * 2, true);
        ctx.strokeStyle = 'black';
        ctx.stroke();
        myCanvas.requestPaint();
    }


}










