
cc = g++
cflags = -g -std=c++17 -Wall -Wextra -Wpedantic

cfiles = $(shell find src -name "*.cc")
hfiles = $(shell find src -name "*.h")
ofiles = $(subst src/,build/src/,$(cfiles:.cc=.o))
dfiles = $(ofiles:.o=.d)

scripts = $(shell find scripts -name "*.cc")
scriptbuilds = $(subst scripts/,build/scripts/,$(scripts:.cc=))

subfolders = $(shell find src -type d)
buildfolders = $(addprefix build/,$(subfolders)) build build/scripts

.PHONY: all clean

all: $(scriptbuilds)

clean:
	rm -rf build

$(buildfolders):
	mkdir -p $@

build/scripts/%: scripts/%.cc $(ofiles)
	$(cc) $(cflags) -MMD -MP -o $@.o -c $<
	$(cc) $(cflags) -o $@ $(ofiles) $@.o

-include $(dfiles)

build/%.o: %.cc | $(buildfolders)
	$(cc) $(cflags) -MMD -MP -o $@ -c $<