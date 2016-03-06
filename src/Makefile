# Target executable name
TARGET = ./compiled/DCframework

#OBJ directory
OBJ_DIR=../obj

#SRC directory
SRC_DIR=.

#CXX = Compiler
CXX=g++

# Source files
SOURCES = main.cpp Framework.cpp Problem.cpp Solution.cpp FibonacciP.cpp FibonacciS.cpp MergeSortP.cpp MergeSortS.cpp StrassenP.cpp BubbleSort.cpp Statistics.cpp

# Work out names of object files from sources
#OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS=$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/Framework.o \
	$(OBJ_DIR)/Problem.o \
	$(OBJ_DIR)/Solution.o \
	$(OBJ_DIR)/FibonacciP.o \
	$(OBJ_DIR)/FibonacciS.o \
	$(OBJ_DIR)/MergeSortP.o \
	$(OBJ_DIR)/MergeSortS.o \
	$(OBJ_DIR)/BubbleSort.o \
	$(OBJ_DIR)/StrassenP.o \
	$(OBJ_DIR)/Statistics.o \

# Flags
CXXFLAGS = -g -O2 -std=c++11 -I.

# Default target (to build all)
all: ${TARGET}

# Clean target
clean:
		rm ${OBJECTS} ${TARGET}
		
# Rule to link object files to create target executable
${TARGET}: ${OBJECTS}
		${LINK.cc} -o $@ $^
		
# Rule to compile each required object (class)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		$(CXX) -c -o $@ $(CXXFLAGS) $<

# Header dependencies
$(OBJ_DIR)/Framework.o: headers/Framework.hpp
$(OBJ_DIR)/Problem.o: headers/Problem.hpp
$(OBJ_DIR)/Solution.o: headers/Solution.hpp
$(OBJ_DIR)/FibonacciP.o: headers/FibonacciP.hpp
$(OBJ_DIR)/FibonacciS.o: headers/FibonacciS.hpp
$(OBJ_DIR)/MergeSortP.o: headers/MergeSortP.hpp
$(OBJ_DIR)/MergeSortS.o: headers/MergeSortS.hpp
$(OBJ_DIR)/BubbleSort.o: headers/BubbleSort.hpp
$(OBJ_DIR)/StrassenP.o: headers/StrassenP.hpp
$(OBJ_DIR)/Statistics.o: headers/Statistics.hpp