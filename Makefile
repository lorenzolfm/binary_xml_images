# Make will print nothing by default
ifndef VERBOSE
.SILENT:
endif

# Name of the component, used for the executable
PROJECT_NAME = BinaryXMLParser

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

# Compiler
CC = g++

# Compiler flags
C_FLAGS = -g -Werror

# Linker flags
LD_FLAGS = -L $(GTEST_LIB) -l $(GTEST) -l pthread

# Gtest stuff
GTEST_LIB = /usr/lib/
GTEST = gtest

# Project directories
INCLUDE_DIR = include
SRCS_DIR = src
TESTS_DIR = tests
BUILD_DIR = build

BUILD_OUTPUT = -o $(BUILD_DIR)

# Compile and link the whole project
all: $(BUILD_DIR)/main.o
	$(CC) $(C_FLAGS) $? $(BUILD_OUTPUT)/main

build/main.o: $(SRCS_DIR)/main.cpp
	mkdir -p build
	$(CC) -c $(C_FLAGS) $(SRCS_DIR)/$(*F).cpp -o $@

run:
	./$(BUILD_DIR)/main

test: $(BUILD_DIR)/test_xml_parser.o
	$(CC) $(C_FLAGS) $? $(LD_FLAGS) $(BUILD_OUTPUT)/TestXMLParser
	./$(BUILD_DIR)/TestXMLParser

build/test_xml_parser.o: $(TESTS_DIR)/test_xml_parser.cpp
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(TESTS_DIR)/$(*F).cpp -o $@
