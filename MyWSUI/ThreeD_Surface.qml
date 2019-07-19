/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Data Visualization module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.7
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtDataVisualization 1.0
import Core 1.0
import "."

ApplicationWindow {
    //currently, data copying in populate_model is taking too much time, needs to optimize it.
    id: threeD_Surface
    MyModel{
        id: myModel
    }
    width: 1050
    height: 800
    function populate_model()
    {   var plotx = surfaceData.dataX, ploty = surfaceData.dataY, plotz = surfaceData.dataZ;
        for(var i=0; i<plotx.length; i++){
             myModel.model.append({"row": plotx[i], "col": ploty[i], "value": plotz[i]});
        }
        console.log('data copied');
    }

Rectangle {
    id: mainview
    width: 1024
    height: 768
    color: surfacePlot.theme.windowColor
        MyData {
            id: surfaceData
            onDataLoaded:{

                populate_model();
            }

            }
    Item {
        id: surfaceView
        width: mainview.width
        height: mainview.height
        anchors.top: mainview.top
        anchors.left: mainview.left

        //! [0]
        ColorGradient {
            id: surfaceGradient
            ColorGradientStop { position: 0.0; color: "darkslategray" }
            ColorGradientStop { id: middleGradient; position: 0.25; color: "peru" }
            ColorGradientStop { position: 1.0; color: "red" }
        }

        Surface3D {
            id: surfacePlot
            width: surfaceView.width
            height: surfaceView.height
            theme: Theme3D {
                type: Theme3D.ThemeStoneMoss
                font.family: "STCaiyun"
                font.pointSize: 35
                colorStyle: Theme3D.ColorStyleRangeGradient
                baseGradients: [surfaceGradient]
            }
            shadowQuality: AbstractGraph3D.ShadowQualityMedium
            selectionMode: AbstractGraph3D.SelectionSlice | AbstractGraph3D.SelectionItemAndRow
            scene.activeCamera.cameraPreset: Camera3D.CameraPresetIsometricLeft
            axisY.min: -300.0
            axisY.max: 300.0
            axisX.segmentCount: 10
            axisX.subSegmentCount: 2
            axisX.labelFormat: "%i"
            axisZ.segmentCount: 10
            axisZ.subSegmentCount: 2
            axisZ.labelFormat: "%i"
            axisY.segmentCount: 5
            axisY.subSegmentCount: 2
            axisY.labelFormat: "%i"


            Surface3DSeries {
                id: surfaceSeries
                flatShadingEnabled: false
                drawMode: Surface3DSeries.DrawSurface

                ItemModelSurfaceDataProxy {
                    itemModel: myModel.model
                    rowRole: "row"
                    columnRole: "col"
                    yPosRole: "value"
                }
                onDrawModeChanged: checkState()
            }

            }
            //! [4]
        }


    RowLayout {
        id: buttonLayout
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        opacity: 0.5

        Button {

            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "Plot Surface"

            onClicked: {
                surfaceData.show("/wafermap.csv");
            }

        }
}
}
}
