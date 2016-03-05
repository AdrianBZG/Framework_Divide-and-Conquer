# Target executable name
TARGET = ./compiled/DCframework

#OBJ directory
OBJ_DIR=../obj

#SRC directory
SRC_DIR=.

#CXX = Compiler
CXX=g++

# Source files
SOURCES = main.cpp Framework.cpp Problem.cpp Solution.cpp

# Work out names of object files from sources
#OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS=$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/Framework.o \
	$(OBJ_DIR)/Problem.o \
	$(OBJ_DIR)/Solution.o \

# Flags
CXXFLAGS = -std=c++11 -I.

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