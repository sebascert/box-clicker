target := game

source_dir  := src
include_dir := include
build_dir   := build

# sources and objects
sources := $(shell find $(src_dir) -name '*.cpp')
objs    := $(sources:.cpp=.o)

# env setup
CXX         := g++
CXXSTD      := c++17
LIB_SFML    := -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS    := -Wall -Wextra -std=$(CXXSTD) -I $(include_dir)
ifeq ($(BUILD),release)
	target += _release
	CXXFLAGS += -O2
else
	CXXFLAGS += -g
endif

all: $(target)

$(target): $(build_dir)/$(target)

$(build_dir)/$(target): $(objs) | $(build_dir)
	@$(CXX) $(CXXFLAGS) $(LIB_SFML) $^ -o $@

%.o: %.cpp
	@echo "compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all

$(build_dir):
	@mkdir -p $(build_dir)

clean:
	@find . -name '*.o' -delete
	@rm -rf $(build_dir)

.PHONY: clean
