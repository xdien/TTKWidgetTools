# ***************************************************************************
# * This file is part of the TTK Widget Tools project
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

TEMPLATE = lib
CONFIG += plugin lib

include($$PWD/TTKModule.pri)
include($$PWD/../TTKWidgetTools.pri)

include(../../../common.pri)
DEST_INCLUDE_DIR = $$PWD/../../../include/TTKCore
DEFINES += TTK_LIBRARY
CONFIG(debug, debug|release) {
    TARGET = TTKCored
} else {
    TARGET = TTKCore
}

win32:RC_FILE = $$PWD/TTKCore.rc

EXTRA_FILES += $$HEADERS
#deploy
unix:{
    DESTDIR  = $${DEST_LIBS}
    linux{
        QMAKE_POST_LINK += mkdir -p $$quote($${DEST_INCLUDE_DIR}) $$escape_expand(\\n\\t) # qmake need make mkdir -p on subdirs more than root/
        for(FILE,EXTRA_FILES){
            QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE) $$quote($${DEST_INCLUDE_DIR}) $$escape_expand(\\n\\t) # inside of libs make /include/files
        }
    }
    macx{
        QMAKE_POST_LINK += mkdir -p $$quote($${DEST_INCLUDE_DIR}) $$escape_expand(\\n\\t) # qmake need make mkdir -p on subdirs more than root/
        for(FILE,EXTRA_FILES){
            QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE) $$quote($${DEST_INCLUDE_DIR}) $$escape_expand(\\n\\t)
        }
        QMAKE_POST_LINK += mkdir -p $$quote($${DESTDIR}/include) $$escape_expand(\\n\\t)
    }
}

win32: {
    DESTDIR = $${DEST_LIBS}
        EXTRA_FILES ~= s,/,\\,g
        BUILD_DIR ~= s,/,\\,g
        DEST_DIR ~= s,/,\\,g
        DEST_INCLUDE_DIR ~= s,/,\\,g
        QMAKE_POST_LINK += if not exist $$quote($${DEST_INCLUDE_DIR}) mkdir $$quote($${DEST_INCLUDE_DIR}) $$escape_expand(\\n\\t)# qmake need make mkdir -p on subdirs more than root/
        for(FILE,EXTRA_FILES){
            QMAKE_POST_LINK += $$QMAKE_COPY \"$$FILE\" \"$${DEST_INCLUDE_DIR}\" $$escape_expand(\\n\\t)
        }

}
