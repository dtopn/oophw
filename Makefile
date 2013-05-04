#ifeq($(PROCESSOR_ARCHITECTURE), AMD64)
#DEBUG := 1
#BASE	= ./
CC 	= g++
CFLAGS 	= -c #-Wall
LDFLAGS =

EXEC = pdadd pdremove pdshow pdlist
DEPEND := heure datio
OBJS = heure.o datio.o
OBJRC = $(OBJS: .o=.cpp)
#OBJS +=

OBJDIR	= ./obj
#CFLAGS	+= -g


#.PHONY: clean all

all: 00
	$(foreach var, $(EXEC), $(CC) $(LDFLAGS) -o $(var) $(var).o $(OBJS);)

00: 01
	$(foreach var, $(EXEC) , $(CC) $(CFLAGS) -o $(var).o $(var).cpp $(OBJRC);)

01:
	$(foreach var, $(DEPEND) , $(CC) $(CFLAGS) -o $(var).o $(var).cpp;)



#pdadd:
#	$(CC) -o pdadd pdadd.o $(OBJS)

#pdlist:
#	$(CC) -o pdlist pdlist.o $(OBJS)

#pdremove:
#	$(CC) -o pdremove pdremove.o $(OBJS)

#pdshow:
#	$(CC) -o pdshow pdshow.o $(OBJS)

#$(EXEC):
#	$(CC) -o $(EXEC) $(OBJS)
	
#$(EXEC):
#	$(foreach var, $(EXEC), $(CC) $(CFLAGS) -o $(var) $(var).cpp;)

#.cpp.o:
#	$(CC) $(CFLAGS) $< -o $(OJRDIR)$@

clean:
	$(RM) *.o a.out $(TARGETS) 
