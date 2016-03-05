# Target executable name
TARGET = ./compiled/RAMmachine

#OBJ directory
OBJ_DIR=../obj

#SRC directory
SRC_DIR=.

#CXX = Compiler
CXX=g++

# Source files
SOURCES = main.cpp UI.cpp RAMmachine.cpp Program.cpp Memory.cpp Register.cpp Instruction.cpp Tag.cpp PC.cpp Tape.cpp InTape.cpp OutTape.cpp

# Work out names of object files from sources
#OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS=$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/UI.o \
	$(OBJ_DIR)/RAMmachine.o \
	$(OBJ_DIR)/Program.o \
	$(OBJ_DIR)/Memory.o \
	$(OBJ_DIR)/Register.o \
	$(OBJ_DIR)/Tape.o \
	$(OBJ_DIR)/InTape.o \
	$(OBJ_DIR)/OutTape.o \
	$(OBJ_DIR)/Instruction.o \
	$(OBJ_DIR)/PC.o \
	$(OBJ_DIR)/Tag.o \

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
$(OBJ_DIR)/RAMmachine.o: headers/RAMmachine.hpp
$(OBJ_DIR)/RAMmachine.o: headers/UI.hpp
$(OBJ_DIR)/Program.o: headers/Program.hpp
$(OBJ_DIR)/Memory.o: headers/Memory.hpp
$(OBJ_DIR)/Register.o: headers/Register.hpp
$(OBJ_DIR)/Instruction.o: headers/Instruction.hpp
$(OBJ_DIR)/Tag.o: headers/Tag.hpp
$(OBJ_DIR)/PC.o: headers/PC.hpp
$(OBJ_DIR)/Tape.o: headers/Tape.hpp
$(OBJ_DIR)/InTape.o: headers/InTape.hpp
$(OBJ_DIR)/OutTape.o: headers/OutTape.hpp
