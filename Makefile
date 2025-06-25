ADDR = 2804:1f4a:dcc:ff03::1
PORT = 51511

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude 
LDFLAGS = -lm -g

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude 
LDFLAGS = -lm -g

BIN = bin
OBJ = obj
SRC = src
INCLUDE = include

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

TARGET = $(BIN)/main

all: $(TARGET) 

$(TARGET): $(OBJS) | $(BIN)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
		
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ): 
	mkdir -p $@

run:
	$(TARGET) $(ADDR) $(PORT)

clean:
	rm -rf $(BIN) $(OBJ) $(LOG)
