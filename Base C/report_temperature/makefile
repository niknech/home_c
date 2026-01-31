CC := gcc

SRCS = report.c temp_function.c
OBJS = $(SRCS:.c=.o)

all: main

main: $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	del $(OBJS)