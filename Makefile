# Compiler and flag
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D_GNU_SOURCE -Iinclude

# Sources
SRC_DIR = src
CONFIG_DIR = config
BIN_DIR = bin

# Common files
COMMON_SRC = $(SRC_DIR)/common.c $(CONFIG_DIR)/config.c

# All
all: $(BIN_DIR)/master

# Master
$(BIN_DIR)/master: $(SRC_DIR)/master.c $(COMMON_SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Clean
clean:
	rm -rf $(BIN_DIR)/*