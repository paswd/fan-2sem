FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -std=c++11 -O2
COMPILLER=g++

all: start

start: main.o
	$(COMPILLER) $(FLAGS) -o fan main.o

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

clean:
	@-rm -f *.o *.gch *.dat fan
	@echo "Clean success"
