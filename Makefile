# Starter Makefile
# add .cpp and .h files as specified in each task. 
main: main.o reservoir.o
	g++ main.o reservoir.o -o main 
# g++ main -o main.o reservoir.o
main.o: main.cpp reservoir.h
	g++ -c main.cpp
# g++ main.cpp -c
reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp
# g++ reservoir.cpp -c
clean:
	rm -f main.o reservoir.o