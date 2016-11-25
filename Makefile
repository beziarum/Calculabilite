

GRAPHS=$(patsubst graph/%.c,%,$(wildcard graph/*.c))

all:	$(GRAPHS)



$(GRAPHS): %: graph/%.o gen.o
	gcc -g -Og gen.o graph/$@.o -o $@

clean:
	rm *.o
	rm graph/*.o
	rm $(patsubst %.c,%,$(GRAPHS))
