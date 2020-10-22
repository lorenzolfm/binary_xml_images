# Silent make
ifndef VERBOSE
.SILENT:
endif

# Name of the component, used for the executable
PROJECT_NAME = BinaryXMLParser

# Compiler
CC = g++

# Compiler flags
CPP_FLAGS = -Werror

# Linker flags
LD_FLAGS = -L /usr/lib/ -l gtest -l pthread

# Dependencies flags
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

# Build directory
BUILD_DIR := build
# Include directory
INCLUDE_DIR := include
# Source directory (.cpp files)
SRC_DIR := src
# Test directory
TEST_DIR := tests
# Source objects directory (.o files)
SRCS_OBJS_DIR := $(BUILD_DIR)/objs
# Tests objects directory (.o files)
TESTS_OBJS_DIR := $(SRCS_OBJS_DIR)/tests
# Dependencies directory
DEPDIR = $(SRCS_OBJS_DIR)/.deps

# List of all files matching this pattern (with directory)
SRCS = $(wildcard src/*.cpp)
TESTS = $(wildcard tests/*cpp)
# List of all files matching this pattern (file only)
SRCS_FILES = $(notdir $(SRCS))
TESTS_FILES = $(notdir $(TESTS))

# Substitutes the file extension from %.cpp to %.o and sets the corrrect path
OBJS := $(patsubst %.cpp, $(SRCS_OBJS_DIR)/%.o, $(SRCS_FILES))
TEST_OBJS := $(patsubst %.cpp, $(TESTS_OBJS_DIR)/%.o, $(TESTS_FILES))

# Build object files
COMPILE = $(CC) -I $(INCLUDE_DIR) $(DEPFLAGS) $(CPP_FLAGS) -c

$(SRCS_OBJS_DIR)/%.o : $(SRC_DIR)/%.cpp $(DEPDIR)/%.d | $(DEPDIR)
	mkdir -p $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(TESTS_OBJS_DIR)/%.o : $(TEST_DIR)/%.cpp $(DEPDIR)/%.d | $(DEPDIR)
	mkdir -p $(SRCS_OBJS_DIR)/tests
	$(COMPILE) $< -o $@

test : $(TEST_OBJS) $(OBJS)
	$(CC) $(TESTS) $(SRCS) -I $(INCLUDE_DIR) $(LD_FLAGS) -o $(BUILD_DIR)/test
	./build/test

all : $(OBJS)
	$(CC) main.cpp $(SRCS) -I $(INCLUDE_DIR) -o $(BUILD_DIR)/$(PROJECT_NAME)

run : all
	./$(BUILD_DIR)/$(PROJECT_NAME) dataset03.xml

# Doxygen support
DOCS_OUT_DIR = docs

export DOCS_OUT_DIR = docs
export DOXYGEN_PROJECT_NAME = $(PROJECT_NAME)
export DOXYGEN_GENERATE_LATEX = NO
export DOXYGEN_GENERATE_TREEVIEW = YES
export DOXYGEN_ALPHABETICAL_INDEX = NO
export DOXYGEN_OUTPUT_DIRECTORY = $(DOCS_OUT_DIR)
export DOXYGEN_RECURSIVE = YES
export DOXYGEN_HTML_OUTPUT = .

doc:
	@doxygen
	@echo "Documentation @ ${DOCS_OUT_DIR}/index.html"

# Format code using clang-format
format:
	find \
	src \
	include \
	tests \
	-name "*.h" \
	-o -name "*.cpp" \
	| xargs clang-format -i .clang-format

# Clean build and docs directories
clean:
	rm -rf build
	rm -rf docs

# Create dependencies directory
$(DEPDIR): ; @mkdir -p $@

# Creates dependencies
DEPFILES := $(SRCS_FILES:%.cpp=$(DEPDIR)/%.d) $(TESTS_FILES:%.cpp=$(DEPDIR)/%.d)
$(DEPFILES):

include $(wildcard $(DEPFILES))
