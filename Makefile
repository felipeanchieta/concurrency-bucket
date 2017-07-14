CXX:=clang++

CXX_FLAGS=--std=c++11 -Wall -Wpedantic -g
LIBS=-pthread

.PHONY: all clean

all: bin bin/atomic bin/mutex bin/race_conditions bin/tasks

bin:
	@echo "Creating bin dir..."
	@mkdir -p bin

bin/atomic: src/atomic.cpp
	@echo "Compiling the file $^"
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBS)

bin/mutex: src/mutex.cpp
	@echo "Compiling the file $^"
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBS)

bin/race_conditions: src/race_conditions.cpp
	@echo "Compiling the file $^"
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBS)

bin/tasks: src/tasks.cpp
	@echo "Compiling the file $^"
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBS)

clean:
	@echo "Cleaning..."
	@$(RM) -rf bin
