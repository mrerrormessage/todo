CC=gcc
CFLAGS=-Wall -g
GTKFLAGS=$(pkg-config --cflags --libs gtk+-2.0 gmodule-2.0)


all:
	$(CC) `pkg-config --cflags --libs gtk+-2.0` $(CFLAGS) -o todo todo.c list.c item.c