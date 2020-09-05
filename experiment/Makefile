Debug_Level=-O3 -Wall 
CC=g++
CXXFLAGS=-c  $(Debug_Level) -std=c++11  -Wall 
 


sequence: 
	$(CC) $(CXXFLAGS) ./sequence.cpp
	$(CC) -o sequence *.o 

random:
	$(CC) $(CXXFLAGS) ./random.cpp
	$(CC) -o random *.o 

clean:
	rm -f ./*.o ./*.d ./*exe ./*stackdump sequence random
