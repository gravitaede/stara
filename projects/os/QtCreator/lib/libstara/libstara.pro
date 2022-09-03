########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: libstara.pro
#
# Author: $author$
#   Date: 9/3/2022
#
# os specific QtCreator project .pro file for framework stara static library libstara
########################################################################
#
# Debug: stara/build/os/QtCreator/Debug/lib/libstara
# Release: stara/build/os/QtCreator/Release/lib/libstara
# Profile: stara/build/os/QtCreator/Profile/lib/libstara
#
include(../../../../../build/QtCreator/stara.pri)
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/lib/libstara/libstara.pri)

TARGET = $${libstara_TARGET}
TEMPLATE = $${libstara_TEMPLATE}
CONFIG += $${libstara_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libstara_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libstara_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libstara_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libstara_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libstara_HEADERS} \
$${libstara_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libstara_SOURCES} \

########################################################################

