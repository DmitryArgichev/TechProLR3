all: rebuild 

rebuild: main.cpp
	g++ -Wall -Werror main.cpp -o main.exe
	./main.exe
clean:
	rm main.exe
	
	