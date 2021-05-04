final: main.o wav.o echo.o noisegate.o Processor.o
	g++ -std=c++11 -o final main.o wav.o echo.o noisegate.o Processor.o

main.o: main.cpp wav.h echo.h normalization.h noisegate.h Processor.h
	g++ -c -std=c++11 main.cpp

wav.o: wav.cpp wav.h
	g++ -c -std=c++11 wav.cpp

echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c -std=c++11 noisegate.cpp

Processor.o: Processor.cpp Processor.h
	g++ -c -std=c++11 Processor.cpp
clean:
	rm *.o final
