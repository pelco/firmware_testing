
CPPUTEST_HOME=../tools/cpputest

TEST_DIR=tests/

# Name of the test binary
TEST_TARGET=$(TEST_DIR)/test_firmware
# Flags for TEST_TARGET binary
CPPUTEST_EXE_FLAGS=-v -c

# Memory leak example
CPPUTEST_USE_MEM_LEAK_DETECTION=N

# Flags for the C++ AND C preprocessor
CPPUTEST_CPPFLAGS= -DTEST_MAIN
# Flags for the C++ compiler
CPPUTEST_CXXFLAGS= -std=c++14
# Linker flags
CPPUTEST_LDFLAGS= -lpthread

# Include extensions lib
CPPUTEST_USE_EXTENSIONS=Y

SRC_DIRS = 		\
	src/		\

# Where the cpputest library is located
INCLUDE_DIRS = 					\
	$(CPPUTEST_HOME)/include	\
	src/include/ 				\

TEST_SRC_DIRS = \
	$(TEST_DIR)	\

MOCKS_SRC_DIRS = 		\
	$(TEST_DIR)/mocks	\

CPPUTEST_OBJS_DIR=$(TEST_DIR)/build/
CPPUTEST_LIB_DIR=$(TEST_DIR)/lib

# Run MakefileWorker.mk with the variables defined here
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
