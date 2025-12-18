CC := gcc

SRCS = main.c sensor.c
OBJS = $(SRCS:.c=.o)

all: prog

prog: $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	del prog.exe $(OBJS)