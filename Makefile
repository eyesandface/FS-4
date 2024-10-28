Compiler = g++
CompilerFlags = -Wall -Wextra
Executable = redirect-cin
SourceFiles = redirect-cin.cpp
ObjectFiles = redirect-cin.o


all: redirect-cin


redirect-cin: redirect-cin.o
	$(Compiler) $(CompilerFlags) -o redirect-cin redirect-cin.o


redirect-cin.o: redirect-cin.cpp
	$(Compiler) $(CompilerFlags) -c redirect-cin.cpp -o redirect-cin.o


clean:
	rm -f redirect-cin.o redirect-cin
