CC = gcc
CFLAGS = -Wall
objects = Day05.o

all: Day05

Day05: $(objects)
	$(CC) $(CFLAGS) $^ -o Day05

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o Day05
