# I hate Makefiles and I have no idea what's going on here

LD=ld
CC=gcc
CFLAGS=-c -std=c99 -fdiagnostics-color=always 
INCLUDE=-I/usr/include/x86_64-linux-gnu
LDFLAGS=-L/usr/lib/x86_64-linux-gnu -lSDL2
SOURCES=src/main.c src/system.c src/opcodes.c src/window.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=bin/eightchips

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(INCLUDE) $(OBJECTS) -o $@ $(LDFLAGS)  
	
.c.o:
	$(CC) $(INCLUDE) $(LDFLAGS) $(CFLAGS) $< -o $@
	
clean:
	$(RM) bin/eightchips src/*.o
