#*******************************************************************************
# @Description : Template for Makefile, build obj files into seperate build directory
# @Author      : phillee (email: phillee2016@163.com)
# @Date        : 2021-07-07
# @LICENSE     : Copyright (c) phillee 2021. All Rights Reserved.
#*******************************************************************************
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

CC := gcc
CC_FLAGS := -g -Wall
RM := rm -rf

CUR_DIR = $(shell pwd)
CUR_TIM = $(shell date)
SRC_C = $(wildcard $(CUR_DIR)/$(SRC_DIR)/*.c)
OBJ_C = $(addprefix $(BUILD_DIR)/,$(patsubst %.c,%.o,$(notdir $(SRC_C))))
TARGET = $(addprefix $(BIN_DIR)/, $(patsubst %.c,%,$(notdir $(SRC_C))))
# The following command can also implement such function
#TARGET = $(addprefix $(BIN_DIR)/, $(basename $(notdir $(SRC_C))))

all: $(TARGET)

#$(TARGET): $(OBJ_C)
#	$(info Build time: $(CUR_TIM))
#	$(info Build path: $(CUR_DIR)/$(BUILD_DIR))
#	$(CC) -o $@ $^

#$(BUILD_DIR)/%.o: $(SRC_C)
#	$(CC) -c $(CC_FLAGS) $< -o $(CUR_DIR)/$@

$(BIN_DIR)/%: $(BUILD_DIR)/%.o
	$(CC) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CC_FLAGS) $< -o $@

.PHONY : clean

clean:
	$(RM) $(TARGET) $(BUILD_DIR)/*.o
