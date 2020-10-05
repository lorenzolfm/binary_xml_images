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

# Gtest stuff
GTEST_LIB = /usr/lib/
GTEST = gtest

# Linker flags
LD_FLAGS = -L $(GTEST_LIB) -l $(GTEST) -l pthread
