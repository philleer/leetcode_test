TARGET := main_test

CC := gcc
CC_FLAGS := -Wall

RM := rm -rf

$(TARGET): two_sum.o
	$(CC) -o $^ two_sum.o

clean:
	$(RM) $^ two_sum.o
