Debug_Level=-O3 -Wall 
CC=g++
CXXFLAGS=-c  $(Debug_Level) -std=c++11  -Wall 
 


sequence: 
	$(CC) $(CXXFLAGS) ./sequence.cpp
	$(CC) -o sequence *.o 

clean:
	rm -f ./*.o ./*.d ./*exe ./*stackdump sequence 
