out : main.o
	g++ main.o -o out

main.o : main.cpp
	g++ -c main.cpp -o main.o

clean :
	rm out *.o

distclean :
	rm out *.o *.txt