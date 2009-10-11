BIN = quax
SRCS= main.cpp quax.cpp
OBJS= $(SRCS:.cpp=.o)

CC= g++
CCFLAGS= -g -Wall -Iinclude -O0 -pipe
LD= g++
LDFLAGS= -g $(LIBS)

all: $(BIN)

%.o: %.cpp
	$(CC) $(CCFLAGS) $(LIBS) -o $@ -c $<

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

dist:
	-rm cppbot.tar.bz2
	(cd ..; tar cjf cppbot.tar.bz2 cppbot; mv cppbot.tar.bz2 cppbot/)

clean:
	-rm -f *.o $(BIN)

dist-clean: clean
	-rm cppbot.tar.bz2

.PHONY: all dist clean
