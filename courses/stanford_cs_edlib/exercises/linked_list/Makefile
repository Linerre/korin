basics := basics.c
CFLAGS := -Wall -Werror -std=c11
problems := p01 p02
outs = p01.out p02.out

all: $(outs)

$(outs): $(foreach p, $(problems), $(p).c)
	$(CC) $(CFLAGS) -o $@ $< $(basics)

p01: p01.c
	$(CC) $(CFLAGS) -o $@.out p01.c $(basics)

p02: $(basics) p02.c
	$(CC) $(CFLAGS) -o $@.out p02.c $(basics)

clean:
	rm -f *.out
