all: rebuild 

rebuild: TechProLR3.cpp
	g++ -Wall -Werror TechProLR3.cpp -o TechProLR3.exe
	./TechProLR3.exe
clean:
	rm TechProLR3.exe
	
	