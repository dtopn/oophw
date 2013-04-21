#ifeq($(PROCESSOR_ARCHITECTURE), AMD64)
#DEBUG := 1
#BASE	= ./
CC 	= g++
CFLAGS 	= -c -Wall
#LDFLAGS =
EXECUTABLE = assn02

#LOC	= ./
OBJS 	= assn02.o LinkedList.o ListNode.o Student.o Class.o Course.o

#CFLAGS	+= -g

#all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)     
	$(CC) -o $(EXECUTABLE) $(OBJS)
	

#endif

clean:
	rm *.o
