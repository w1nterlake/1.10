BUILD_RELEASE = build/src
BUILD_DEBUG = build/debug

source = main.cpp function.cpp

OBJECT_RELEASE = $(patsubst %.cpp,$(BUILD_RELEASE)/%.o,$(source))
OBJECT_DEBUG = $(patsubst %.cpp,$(BUILD_DEBUG)/%.o,$(source))

release: $(OBJECT_RELEASE)
	g++ -pthread $^ -o a.out
debug: $(OBJECT_DEBUG)
	g++ -pthread $^	-o b.out

$(BUILD_RELEASE)/%.o: %.cpp
	mkdir -p $(BUILD_RELEASE)
	g++ -c -O3 -march=native -ffast-math -funroll-loops -flto -DNDEBUG $< -o $@

$(BUILD_DEBUG)/%.o: %.cpp
	mkdir -p $(BUILD_DEBUG)
	g++ -c -pthread -g3 -O0 -Wall -Wextra -fno-omit-frame-pointer -fno-inline $< -o $@