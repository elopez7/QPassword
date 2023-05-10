// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0

import QtQuick
import QtQuick.Controls
import QPasswordApp

ApplicationWindow {
    id: appWindow
    width: Screen.width
    height: Screen.height
    color: Constants.backgroundColor
    visible: true
    title: "QPasswordApp"

    Screen01 {
        id: mainScreen
        anchors.fill: appWindow
    }

}

