ROOT=.
SRC_DIR=$(ROOT)/src
BUILD_DIR = build

CC = gcc

CFLAGS=-ansi -I$(ROOT)/include -Wall -DLINUX -D_GNU_SOURCE

LIBAPUE=$(ROOT)/lib/libapue.a
LDLIBS=-L$(ROOT)/lib -lapue -pthread

C_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)

all: linux-api-demo

linux-api-demo:$(OBJ_FILES) $(LIBAPUE)
	gcc -o linux-api-demo $(OBJ_FILES) $(LDLIBS)

$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c	
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -c -g -o $@
	
clean:
	rm -rf $(BUILD_DIR) linux-api-demo



