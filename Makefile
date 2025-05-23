target := game

source_dir  := src
include_dir := include
build_dir   := build

# sources and objects
sources := $(shell find $(source_dir) -name '*.cpp')
headers := $(shell find $(include_dir) -name '*.hpp')
objs    := $(sources:.cpp=.o)

# env setup
CXX         := g++
CXXSTD      := c++17
LIB_SFML    := -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS    := -Wall -Wextra -std=$(CXXSTD) -I$(include_dir)
ifeq ($(BUILD),release)
	target += _release
	CXXFLAGS += -O2
else
	CXXFLAGS += -g
endif

CLANGDB   := compile_commands.json

MAKEFLAGS += --no-print-directory

# target rules
all: $(target)

$(target): $(build_dir)/$(target)

.PHONY: all

# utils rules
format:
	@clang-format -i $(headers) $(sources)

lint: $(CLANGDB)
	@clang-tidy $(headers) $(sources) -p .

lint-fix: $(CLANGDB)
	@clang-tidy $(headers) $(sources) -p . --fix

clangdb: clean-clangdb
	@$(MAKE) $(CLANGDB)

.PHONY: format lint clangdb

# compilation rules
$(build_dir)/$(target): $(objs) | $(build_dir)
	@$(CXX) $^ $(CXXFLAGS) $(LIB_SFML) -o $@

%.o: %.cpp
	@echo "compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(CLANGDB):
	@$(MAKE) clean
	@bear -- $(MAKE) $(objs)

$(build_dir):
	@mkdir -p $(build_dir)

# clean rules
clean:
	@find . -name '*.o' -exec rm -f {} +
	@rm -rf $(build_dir)

clean-clangdb:
	@rm -f $(CLANGDB)
	@rm -rf .cache/clangd

clean-all: clean clean-clangdb

.PHONY: clean clean-clangdb clean-all
