
# CISP 400 - Makefile template
# This is a makefile template for use on Linux
# systems.  It is intended to be a template for
# a VERY simple makefile to compile all C++ (.cpp)
# files in a directory.
#
# To run it, you go down to the BIN variable and
# change it from:
#
# BIN=example
#
# to read whatever you want the output program to be.
# For instance, if you want the output program to be
# myassignment, you type:
#
# BIN=myassignment
#
# The makefile does the rest for you.
#
# Put this makefile into the project directory.  To
# compile your files, you just type:
#
# make
#
# And only the changed files will be compiled.
#
# If you need to compile ALL the files, then you
# type:
#
# make clean
#
# And the old output files will be purged.  This will
# delete your runnable program, if there is one, and
# all object files.  It will NOT touch your C++ files or
# header files.
#
# In order to compute what source files need what
# header files, this makefile will produce a hidden
# text file in the directory you run it in: .depend
#
# It is safe to delete this file, but it is not necessary,
# and it should be cleaned up with the rest of the output
# files on 'make clean'.
#
# Much of this is based on work available at:
#
# https://opensource.com/article/18/8/what-how-makefile

CC=g++
LINKFLAGS=-Wall -g -ggdb
CFLAGS=-Wall -g -ggdb -std=c++11 -c

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
BIN=main

# This section assembles the dependencies for the header
# files in case those change.
#
# Credit: https://stackoverflow.com/questions/2394609/makefile-header-dependencies

all: $(BIN)

depend: .depend

.depend: $(SRC)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;

include .depend

$(BIN): $(OBJ)
	$(CC) $(LINKFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm $(OBJ) $(BIN) .depend


