audio: main.cpp echo.o normalization.o noisegate.h Processor.o
	g++ -std=c++11 -o audio main.cpp echo.o normalization.o noisegate.h Processor.o

echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c -std=c++11 noisegate.cpp

Processor.o: Processor.cpp Processor.h
	g++ -c -std=c++11 Processor.cpp
clean:
	rm *.o audio
