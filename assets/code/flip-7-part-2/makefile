
cc = g++
cflags = -g

cfiles = $(shell find . -name "*.cc")
hfiles = $(shell find . -name "*.h")
ofiles = $(addprefix build/,$(cfiles:.cc=.o))
dfiles = $(ofiles:.o=.d)

subfolders = $(filter-out build,$(shell find . -type d))
buildfolders = $(addprefix build/,$(subfolders)) build

.PHONY: all clean

all: build/main
	$(cc) $(cflags) -o main $(ofiles)

clean:
	rm -rf build/*

$(buildfolders):
	mkdir -p $@

build/main: $(ofiles) | $(buildfolders)
	$(cc) $(cflags) -o $@ $(ofiles)

-include $(dfiles)

build/%.o: %.cc build | $(buildfolders)
	$(cc) $(cflags) -MMD -MP -o $@ -c $<