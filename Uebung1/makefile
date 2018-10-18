CC = gcc
CFLAGS = -g -Wall
OBJECTS = DynList.o

DynList:$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) -c $<
