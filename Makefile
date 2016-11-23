

GRAPHS=$(patsubst graph/%.c,%,$(wildcard graph/*.c))

all:	$(GRAPHS)



$(GRAPHS): %: graph/%.o main.o
	gcc -g -Og main.o graph/$@.o -o $@

clean:
	rm *.o
	rm graph/*.o
	rm $(patsubst %.c,%,$(GRAPHS))
