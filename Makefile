#ifeq($(PROCESSOR_ARCHITECTURE), AMD64)
#DEBUG := 1
#BASE	= ./
CXX	= g++
CFLAGS 	= -c -Wall
#LDFLAGS =
EXECUTABLE = assn06

#LOC	= ./
OBJS 	= assn06.o Fraction.o

#CFLAGS	+= -g

#all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)     
	$(CXX) -o $(EXECUTABLE) $(OBJS)

#assn06: Fraction.o assn06.o
#	g++ -o assn06 assn06.o Fraction.o
	
#Fraction.o:
#	g++ -c -o Fraction.o Fraction.cpp
	
#assn06.o:
#	g++ -c -o assn06.o assn06.cpp

#endif

clean:
	rm *.o