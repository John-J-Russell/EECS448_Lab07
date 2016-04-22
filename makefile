TestingProgram: main.o Test.o
	g++ -g -Wall -std=c++11 main.o Test.o -o TestingProgram

main.o: main.cpp Node.h Node.hpp LinkedList.h LinkedList.hpp Test.o
	g++ -g -Wall -std=c++11 -c main.cpp

Test.o: Node.h Node.hpp LinkedList.h LinkedList.hpp
	g++ -g -Wall -std=c++11 -c Test.cpp

clean:
	rm *.o TestingProgram
