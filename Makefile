output: main.o 
	g++ main.o -o mysort

main.o: main.cpp sorts.h
	g++ -c main.cpp

clean:
	rm*.o output