
CPPUTEST_HOME=../tools/cpputest

TEST_DIR=tests/

# what to call the test binary
TEST_TARGET=$(TEST_DIR)/test_code
# flags for TEST_TARGET
CPPUTEST_EXE_FLAGS=-v -c

# Memory Leak example
CPPUTEST_USE_MEM_LEAK_DETECTION=N

# Coverage report
#CPPUTEST_USE_GCOV=N

# flags for the C++ AND C preprocessor
CPPUTEST_CPPFLAGS= -DTEST_MAIN
# flags for the C++ compiler
CPPUTEST_CXXFLAGS= -std=c++11
# Linker flags
CPPUTEST_LDFLAGS= -lpthread

# Include extensions lib
CPPUTEST_USE_EXTENSIONS=Y

SRC_DIRS = 		\
	src/		\

# where the cpputest library is located
INCLUDE_DIRS = 					\
	$(CPPUTEST_HOME)/include	\
	src/include/ 				\

TEST_SRC_DIRS = \
	$(TEST_DIR)	\

CPPUTEST_OBJS_DIR=$(TEST_DIR)/build/
CPPUTEST_LIB_DIR=$(TEST_DIR)/lib

# run MakefileWorker.mk with the variables defined here
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
