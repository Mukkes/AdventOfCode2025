CC = gcc
CFLAGS = -Wall
objects = Day04.o ../Util/InputUtil.o ../Util/GridUtil.o

all: Day04

Day04: $(objects)
	$(CC) $(CFLAGS) $^ -o Day04

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o Day04
