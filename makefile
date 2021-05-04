final: main.cpp wav.o ui.o
	g++ -std=c++11 -o final main.cpp wav.o ui.o

wav.o: wav.cpp wav.h
	g++ -c -std=c++11 wav.cpp

ui.o: ui.cpp ui.h
	g++ -c -std=c++11 ui.cpp

clean:
	rm *.o final
