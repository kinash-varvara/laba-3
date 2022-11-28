out : main.o fun.o
	g++ main.o fun.o -o out

main.o : main.cpp
	g++ -c main.cpp -o main.o

fun.o : fun.cpp
	g++ -c fun.cpp -o fun.o

clean :
	rm out *.o

distclean :
	rm out *.o *.txt