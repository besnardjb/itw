CC=gcc
LDFLAGS=-L. -lfoo

all: move

move: main
	mkdir -p ./subdir
	cp ./main ./subdir

main: main.c libfoo.so
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

libfoo.so: libfoo.c libfoo.h
	$(CC) $(CFLAGS) -shared -fPIC $^ -o $@

clean:
	rm -fr main libfoo.so ./subdir

#
# Run targets
#

run1: move
	@echo "Running main from current directory"
	./main

run2: move
	@echo "Running main from subdir"
	cd $(PWD)/subdir && ./main