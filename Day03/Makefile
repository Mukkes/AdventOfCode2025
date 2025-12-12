CC = gcc
CFLAGS = -Wall
objects = Day03.o 

all: Day03

Day03: $(objects)
	$(CC) $(CFLAGS) $^ -o Day03

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o Day03
