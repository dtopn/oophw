#ifeq($(PROCESSOR_ARCHITECTURE), AMD64)
#DEBUG := 1
#BASE	= ./
CC 	= g++
CFLAGS 	= -c -Wall
#LDFLAGS =
EXECUTABLE = assn03

#LOC	= ./
OBJS 	= main.o Room.o 

#CFLAGS	+= -g

#all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)     
	$(CC) -o $(EXECUTABLE) $(OBJS)
	

#endif

clean:
	rm *.o
