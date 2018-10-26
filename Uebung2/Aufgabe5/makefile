CC = gcc
CFLAGS = -g -Wall
DEPS = chessboard.h
OBJECTS = chessboard.o springerproblem.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

go:$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

.PHONY : clean
clean :
	$(RM) *.o go
