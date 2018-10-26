CC = gcc
CFLAGS = -g -Wall
DEPS = genList.h
OBJECTS = aufg6.o genList.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

go:$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

.PHONY : clean
clean :
	$(RM) *.o go
