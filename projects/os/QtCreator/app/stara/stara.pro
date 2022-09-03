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
#   File: stara.pro
#
# Author: $author$
#   Date: 9/3/2022
#
# os specific QtCreator project .pro file for framework stara executable stara
########################################################################
#
# Debug: stara/build/os/QtCreator/Debug/bin/stara
# Release: stara/build/os/QtCreator/Release/bin/stara
# Profile: stara/build/os/QtCreator/Profile/bin/stara
#
include(../../../../../build/QtCreator/stara.pri)
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/app/stara/stara.pri)

TARGET = $${stara_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${stara_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${stara_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${stara_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${stara_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${stara_exe_HEADERS} \
$${stara_exe_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${stara_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${stara_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${stara_exe_LIBS} \
$${FRAMEWORKS} \

########################################################################

