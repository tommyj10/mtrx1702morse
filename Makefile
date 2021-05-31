CC=gcc
CFLAGS=-g -Wall -std=c99 -Iinclude
LIBS=
TARGET=morse

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
_DEPS = morse.h
_OBJS = morse.o main.o fatalError.o checkError.o

DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)

