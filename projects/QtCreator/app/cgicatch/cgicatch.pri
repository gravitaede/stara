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
#   File: cgicatch.pri
#
# Author: $author$
#   Date: 9/10/2022
#
# generic QtCreator project .pri file for framework stara executable cgicatch
########################################################################

########################################################################
# cgicatch

# cgicatch TARGET
#
cgicatch_TARGET = cgicatch

# cgicatch INCLUDEPATH
#
cgicatch_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# cgicatch DEFINES
#
cgicatch_DEFINES += \
$${stara_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# cgicatch OBJECTIVE_HEADERS
#
#cgicatch_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.hh \

# cgicatch OBJECTIVE_SOURCES
#
#cgicatch_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.mm \

########################################################################
# cgicatch HEADERS
#
cgicatch_HEADERS += \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/catcher/main_opt.hpp \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/catcher/main.hpp \

# cgicatch SOURCES
#
cgicatch_SOURCES += \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/catcher/main_opt.cpp \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/catcher/main.cpp \

########################################################################
# cgicatch FRAMEWORKS
#
cgicatch_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# cgicatch LIBS
#
cgicatch_LIBS += \
$${stara_LIBS} \

########################################################################
# NO Qt
QT -= gui core

