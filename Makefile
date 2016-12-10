# Compiler
CC=g++
# Flags to compile an object file from source file
CFLAGS=-c
# C++ flags
CPPFLAGS=-std=c++11
# Flags to compile an executed file from object file
OFLAG=-o
# CppUnit library flags
CPPUNIT_FLAGS=-I$CPPUNIT_HOME/include -L$CPPUNIT_HOME/lib -lcppunit
# PCRE library flag
PCRE_FLAG=-lpcrecpp
# Source files folder
SRC=src
# Object files folder
OBJ=obj
# Temp files folder
TEMP=temp
# Test files folder
TEST=test
# Test file
TESTFILE=testfile
# The script on bash which doing the same as the C++ program
SCRIPTFILE=main.sh
# Output executed file name
OFILE=main

all: $(OFILE)

$(OFILE): $(OBJ)/main.o $(OBJ)/ErrorFinder.o $(OBJ)/ErrorFinderTest.o
	$(CC) $(OBJ)/main.o $(OBJ)/ErrorFinder.o $(OBJ)/ErrorFinderTest.o $(PCRE_FLAG) $(CPPUNIT_FLAGS) $(CPPFLAGS) $(OFLAG) $(OFILE)

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/main.o
	
$(OBJ)/ErrorFinder.o: $(SRC)/ErrorFinder/ErrorFinder.cpp
	$(CC) $(CFLAGS) $(SRC)/ErrorFinder/ErrorFinder.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/ErrorFinder.o
	
$(OBJ)/ErrorFinderTest.o: $(SRC)/ErrorFinderTest/ErrorFinderTest.cpp
	$(CC) $(CFLAGS) $(SRC)/ErrorFinderTest/ErrorFinderTest.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/ErrorFinderTest.o
	
.PHONY: test compare

create_testfile: $(OFILE)
	echo "conftest.c:217: error: 'TIOCSTAT' undeclared (first use in this function)" > $(TEST)/$(TESTFILE)
	echo "conftest.c:238: fatal error: 'struct dirent' has no member named 'd_namlen'" >> $(TEST)/$(TESTFILE)
	echo "conftest.c:217: error: (Each undeclared identifier is reported only once" >> $(TEST)/$(TESTFILE)
	echo "conftest.c:217: error: for each function it appears in.)" >> $(TEST)/$(TESTFILE)
	echo "configure: failed program was:" >> $(TEST)/$(TESTFILE)

test: $(OFILE) create_testfile
	./$(OFILE) < $(TEST)/$(TESTFILE) --test

compare: $(OFILE) create_testfile
	./$(OFILE) < $(TEST)/$(TESTFILE) > $(TEMP)/tmp1
	./$(SCRIPTFILE) < $(TEST)/$(TESTFILE) > $(TEMP)/tmp2
	diff $(TEMP)/tmp1 $(TEMP)/tmp2

clean:
	rm -rf main $(OBJ)/*.o $(TEST)/$(TESTFILE) $(TEMP)/*