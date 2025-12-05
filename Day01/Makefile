CC = gcc
CFLAGS = -Wall
objects = Day01.o 

all: Day01

Day01: $(objects)
	$(CC) $(CFLAGS) $^ -o Day01

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o Day01
