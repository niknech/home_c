CC := gcc

SRCS = main.c sensor.c
OBJS = $(SRCS:.c=.o)

all: main

main: $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	del main.exe $(OBJS)