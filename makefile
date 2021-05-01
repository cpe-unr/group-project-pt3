final: main.cpp wav.o 
	g++ -std=c++11 -o final main.cpp wav.o

wav.o: wav.cpp wav.h
	g++ -c -std=c++11 wav.cpp

clean:
	rm *.o final
