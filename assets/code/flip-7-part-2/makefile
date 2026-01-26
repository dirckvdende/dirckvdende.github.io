
cc = g++
cflags = -g -std=c++17 -Wall -Wextra -Wpedantic

cfiles = $(subst ./,,$(shell find . -name "*.cc"))
hfiles = $(subst ./,,$(shell find . -name "*.h"))
ofiles = $(addprefix build/,$(cfiles:.cc=.o))
dfiles = $(ofiles:.o=.d)

subfolders = $(foreach folder,$(subst ./,,$(shell find . -type d)),$(if $(findstring build,$(folder)),,$(folder)))
buildfolders = $(addprefix build/,$(subfolders)) build

.PHONY: all clean

all: build/main
	$(cc) $(cflags) -o build/main $(ofiles)

clean:
	rm -rf build

$(buildfolders):
	mkdir -p $@

build/main: $(ofiles) | $(buildfolders)
	$(cc) $(cflags) -o $@ $(ofiles)

-include $(dfiles)

build/%.o: %.cc build | $(buildfolders)
	$(cc) $(cflags) -MMD -MP -o $@ -c $<