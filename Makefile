# This is makefile for SFML C++

path = D:\SFML-2.5.1
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
CXXFLAGS =
SFMLFLAGS =
SOURCE = main
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system
#=======================================================================================#

all: compile link run
compile:
	g++ -c $(SOURCE).cpp header.hpp header.cpp Button.hpp Button.cpp SLL.hpp SLL.cpp DataVisualization3.cpp DataVisualization3.hpp Textbox.hpp Textbox.cpp Globals.hpp Globals.cpp ScreenState.hpp DataVisualization4.hpp DataVisualization4.cpp DLL.hpp DLL.cpp -I $(INCLUDE)
link:
	g++ $(CXXFLAGS) $(SOURCE).o header.o Button.o SLL.o DataVisualization3.o Textbox.o Globals.o DataVisualization4.o DLL.o -o main -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
run:
	./${SOURCE}.exe
