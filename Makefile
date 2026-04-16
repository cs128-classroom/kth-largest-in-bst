CXX = clang++
INCLUDES = -Iincludes
CXXFLAGS = -std=c++20 -O0 -gdwarf-4 -Wall -Wextra -Werror -pedantic \
           -fsanitize=address,undefined,implicit-conversion,local-bounds \
           -fno-omit-frame-pointer -fno-optimize-sibling-calls \
           -fsanitize-address-use-after-return=always \
           -Wno-error=unused-parameter \
           $(INCLUDES)

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

exec: bin/exec
tests: bin/tests

bin/exec: includes/node.hpp includes/bst.hpp src/driver.cc | bin
	$(CXX) $(CXXFLAGS) src/driver.cc -o $@

bin/tests: includes/node.hpp includes/bst.hpp tests/tests.cc | bin
	$(CXX) $(CXXFLAGS) tests/tests.cc -o $@

clean:
	rm -rf bin obj