# Starter Makefile
# add .cpp and .h files as specified in each task. 
main: main.o reservoir.o reverseorder.o
	g++ -o main main.o reservoir.o reverseorder.o
# g++ main.o reservoir.o reverseorder -o main
main.o: main.cpp reservoir.h reverseorder.h
	g++ -c main.cpp
# g++ main.cpp -c
reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp
# g++ reservoir.cpp -c
reverseorder.o: reverseorder.cpp
	g++ -c reverseorder.cpp
clean:
	rm -f *.o