C = gcc
CFLAGS = -Wall -g -std=c99
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
	rm -f *.o $(EXEC)

re: fclean all