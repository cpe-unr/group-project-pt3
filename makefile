final: main.o wav.o echo.o ui.o noisegate.o Processor.o
	g++ -std=c++11 -o final main.o wav.o ui.o echo.o noisegate.o Processor.o

main.o: main.cpp wav.h ui.h echo.h normalization.h noisegate.h Processor.h
	g++ -c -std=c++11 main.cpp

wav.o: wav.cpp wav.h
	g++ -c -std=c++11 wav.cpp

ui.o: ui.cpp ui.h
	g++ -c -std=c++11 ui.cpp

echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c -std=c++11 noisegate.cpp

Processor.o: Processor.cpp Processor.h
	g++ -c -std=c++11 Processor.cpp

clean:
	rm *.o final