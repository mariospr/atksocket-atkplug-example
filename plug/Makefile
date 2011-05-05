CC=gcc
TARGET=ta-plug
SOURCES=ta-plug.c \
 	ta-plug-vbox.h \
 	ta-plug-vbox.c \
 	ta-plug-accessible.h \
 	ta-plug-accessible.c \
 	ta-plug-accessible-factory.h \
 	ta-plug-accessible-factory.c

LIBS=atk gtk+-3.0
CFLAGS=`pkg-config --cflags $(LIBS)`
LDFLAGS=`pkg-config --libs $(LIBS)`

all: compile

compile:
	$(CC) -o $(TARGET) $(SOURCES) $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf $(TARGET)
	rm -rf *~
