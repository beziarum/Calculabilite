

GRAPHS=$(patsubst graph/%.c,%,$(wildcard graph/*.c))

all:	$(GRAPHS)



$(GRAPHS): main.o graph/$(GRAPHS).o
	gcc -g -Og main.o graph/$@.o -o $@

clean:
	rm *.o
	rm graph/*.o
	rm $(patsubst %.c,%,$(GRAPHS))
