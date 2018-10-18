CC = gcc
CFLAGS = -g -Wall
OBJECTS = DynList.o

aufg1_1:$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) -c $<
