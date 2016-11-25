

GRAPHS=$(patsubst graph/%.c,%,$(wildcard graph/*.c))

all:	$(GRAPHS) pars

pars: pars.o
	gcc -g -Og pars.o -o pars

$(GRAPHS): %: graph/%.o gen.o
	gcc -g -Og gen.o graph/$@.o -o $@

clean:
	rm -f *.o
	rm -f pars
	rm -f graph/*.o
	rm -f $(patsubst %.c,%,$(GRAPHS))
