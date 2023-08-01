# ***************************************************************************
# * This file is part of the TTK Library Module project
# * Copyright (C) 2015 - 2023 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
#
# * You should have received a copy of the GNU General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
# ***************************************************************************

INCLUDEPATH += \
    $$PWD \
    $$PWD/TTKLibrary \
    $$PWD/TTKDumper

  QT += xml
  HEADERS += \
            $$PWD/TTKLibrary/ttkabstractmovedialog.h \
            $$PWD/TTKLibrary/ttkabstractmoveresizewidget.h \
            $$PWD/TTKLibrary/ttkabstractmovewidget.h \
            $$PWD/TTKLibrary/ttkabstractresizeinterface.h \
            $$PWD/TTKLibrary/ttkabstractthread.h \
            $$PWD/TTKLibrary/ttkabstractxml.h \
            $$PWD/TTKLibrary/ttkany.h \
            $$PWD/TTKLibrary/ttkclickedgroup.h \
            $$PWD/TTKLibrary/ttkclickedlabel.h \
            $$PWD/TTKLibrary/ttkclickedslider.h \
            $$PWD/TTKLibrary/ttkcommandline.h \
            $$PWD/TTKLibrary/ttkconcurrentqueue.h \
            $$PWD/TTKLibrary/ttkcryptographichash.h \
            $$PWD/TTKLibrary/ttkdesktopwrapper.h \
            $$PWD/TTKLibrary/ttkglobalhelper.h \
            $$PWD/TTKLibrary/ttkitemdelegate.h \
            $$PWD/TTKLibrary/ttklibrary.h \
            $$PWD/TTKLibrary/ttklibraryversion.h \
            $$PWD/TTKLibrary/ttksemaphoreloop.h \
            $$PWD/TTKLibrary/ttksuperenum.h \
            $$PWD/TTKLibrary/ttktabbutton.h \
            $$PWD/TTKLibrary/ttktime.h \
            $$PWD/TTKLibrary/ttktoastlabel.h \
            $$PWD/ttkmoduleexport.h \
            $$PWD/ttkqtcompat.h \
            $$PWD/ttkqtglobal.h \
            $$PWD/ttkglobal.h \
            $$PWD/ttklogger.h


SOURCES += \
    $$PWD/TTKLibrary/ttkabstractmoveresizewidget.cpp \
    $$PWD/TTKLibrary/ttkabstractmovedialog.cpp \
    $$PWD/TTKLibrary/ttkabstractmovewidget.cpp \
    $$PWD/TTKLibrary/ttkabstractthread.cpp \
    $$PWD/TTKLibrary/ttkabstractxml.cpp \
    $$PWD/TTKLibrary/ttkany.cpp \
    $$PWD/TTKLibrary/ttkclickedgroup.cpp \
    $$PWD/TTKLibrary/ttkclickedlabel.cpp \
#    $$PWD/TTKLibrary/ttkclickedslider.cpp \
    $$PWD/TTKLibrary/ttkcommandline.cpp \
    $$PWD/TTKLibrary/ttkcryptographichash.cpp \
    $$PWD/TTKLibrary/ttkdesktopwrapper.cpp \
    $$PWD/TTKLibrary/ttkglobalhelper.cpp \
    $$PWD/TTKLibrary/ttkitemdelegate.cpp \
    $$PWD/TTKLibrary/ttksemaphoreloop.cpp \
    $$PWD/TTKLibrary/ttksuperenum.cpp \
    $$PWD/TTKLibrary/ttktabbutton.cpp \
    $$PWD/TTKLibrary/ttktime.cpp \
    $$PWD/TTKLibrary/ttktoastlabel.cpp

