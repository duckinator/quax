BIN = quax
SRCS= main.c
OBJS= $(SRCS:.c=.o)

CC= gcc
CCFLAGS= -g -Wall -Iinclude -O0 -pipe
LD= gcc
LDFLAGS= -g $(LIBS)

all: $(BIN)

.c.o:
	$(CC) $(CCFLAGS) $(LIBS) -o $@ -c $<

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

clean:
	-rm -f *.o $(BIN)

.PHONY: all clean
