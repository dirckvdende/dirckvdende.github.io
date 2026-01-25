
cc = g++
cflags = -g

cfiles = $(shell find -name *.cc)
hfiles = $(shell find -name *.h)
ofiles = $(addprefix build/,$(cfiles:.cc=.o))

.PHONY: clean

main: $(ofiles)
	$(cc) $(cflags) -o main $(ofiles)

clean:
	rm -rf *.o main

build:
	mkdir build

build/%.o: %.cc build $(hfiles)
	$(cc) $(cflags) -o $@ -c $<