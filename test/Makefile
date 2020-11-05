Debug_Level=-O3 -Wall 
CC=g++
CXXFLAGS=-c  $(Debug_Level) -std=c++11  -Wall 
 


main: 
	$(CC) $(CXXFLAGS) ./main.cpp
	$(CC) -o main *.o 

clean:
	rm -f ./*.o ./*.d ./*exe ./*stackdump main
