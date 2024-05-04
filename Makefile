CC := gcc

gtkapp: gtkapp.c
	$(CC) $< -o $@ $(shell pkg-config gtk+-3.0 --cflags --libs)

.PHONY: clean

clean:
	rm gtkapp -f
