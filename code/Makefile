# Makefile

all: src

.PHONY: src
# Build firmware
src:
	make -C src/

.PHONY: test
# Run test cases
test: clean
	make -f MakefileCppUTest.mk

# Run coverage report
.PHONY: coverage
coverage: clean
	mkdir coverage
	make -f MakefileCppUTest.mk CPPUTEST_USE_GCOV=Y gcov
	../tools/lcov/bin/lcov -c -d tests/build/src/ -o coverage/coverageTest.info
	../tools/lcov/bin/genhtml coverage/coverageTest.info --output-directory coverage/coverageTest.html

clean:
	make -f MakefileCppUTest.mk clean
	make -C src/ clean
	rm -rf tests/lib
	rm -rf tests/cpputest_*.xml
	rm -rf coverage
