all: brackets

brackets: stack.o validator.o main.o 
	g++ -std=c++11 main.o stack.o validator.o -o brackets

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o

stack.o: Stack.h Stack.cpp
	g++ -std=c++11 -c Stack.cpp -o stack.o

validator.o: Validator.h Validator.cpp
	g++ -std=c++11 -c Validator.cpp -o validator.o

clean:
	rm -rf *.o *.gch brackets

test:
	./brackets input.txt
