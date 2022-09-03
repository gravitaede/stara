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
#   File: stara.pri
#
# Author: $author$
#   Date: 9/3/2022
#
# generic QtCreator project .pri file for framework stara executable stara
########################################################################

########################################################################
# stara

# stara_exe TARGET
#
stara_exe_TARGET = stara

# stara_exe INCLUDEPATH
#
stara_exe_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# stara_exe DEFINES
#
stara_exe_DEFINES += \
$${stara_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# stara_exe OBJECTIVE_HEADERS
#
#stara_exe_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/xos/app/console/stara/main.hh \

# stara_exe OBJECTIVE_SOURCES
#
#stara_exe_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/xos/app/console/stara/main.mm \

########################################################################
# stara_exe HEADERS
#
stara_exe_HEADERS += \
$${STARA_SRC}/xos/app/console/stara/main_opt.hpp \
$${STARA_SRC}/xos/app/console/stara/main.hpp \

# stara_exe SOURCES
#
stara_exe_SOURCES += \
$${STARA_SRC}/xos/app/console/stara/main_opt.cpp \
$${STARA_SRC}/xos/app/console/stara/main.cpp \

########################################################################
# stara_exe FRAMEWORKS
#
stara_exe_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# stara_exe LIBS
#
stara_exe_LIBS += \
$${stara_LIBS} \

########################################################################
# NO Qt
QT -= gui core

