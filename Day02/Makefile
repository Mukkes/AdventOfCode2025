CC = gcc
CFLAGS = -Wall
objects = Day02.o 

all: Day02

Day02: $(objects)
	$(CC) $(CFLAGS) $^ -o Day02

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o Day02
