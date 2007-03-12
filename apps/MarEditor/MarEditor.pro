include ( ../consoleApps.pri )

TEMPLATE = app
TARGET += marEditor
INCLUDEPATH += . 

CONFIG *= qt   # this needs Qt!

ICON = MarEditor.ico
FORMS += MarEditor.ui

HEADERS += \
	MarEditor.h \
	dockwindow.h

SOURCES +=  \
	main.cpp \
	MarEditor.cpp \
	dockwindow.cpp