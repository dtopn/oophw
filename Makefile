#ifeq($(PROCESSOR_ARCHITECTURE), AMD64)
#DEBUG := 1
#BASE	= ./
CC 	= g++
CFLAGS 	= -c -Wall
<<<<<<< HEAD
LDFLAGS =

EXEC = pdadd pdremove pdshow pdlist
DEPEND := heure.cpp datio.cpp

EXEC = $(SRC: .cpp= ) 
OBJS = heure.o datio.o  
OBJS +=

OBJDIR	= ./obj
#CFLAGS	+= -g


#.PHONY: clean all

all: $(EXEC)

pdadd:
	$(CC) -o pdadd pdadd.o $(OBJS)

pdlist:
	$(CC) -o pdlist pdlist.o $(OBJS)

pdremove:
	$(CC) -o pdremove pdremove.o $(OBJS)

pdshow:
	$(CC) -o pdshow pdshow.o $(OBJS)

#$(EXEC):
#	$(CC) -o $(EXEC) $(OBJS)
	
#$(EXEC):
#	$(foreach var, $(EXEC), $(CC) $(CFLAGS) -o $(var) $(var).cpp;)

#.cpp.o:
	$(CC) $(CFLAGS) $< -o $(OJRDIR)$@

clean:
	$(RM) *.o a.out $(TARGETS) 
=======
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
>>>>>>> assn02
