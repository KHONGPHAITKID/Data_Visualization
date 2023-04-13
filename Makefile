# This is makefile for SFML C++

path = D:\SFML-2.5.1
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
CXXFLAGS = -O2
SFMLFLAGS =
SOURCE = main
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system
#=======================================================================================#

all: compile link run

compile:
	g++ -c $(SOURCE).cpp -I $(INCLUDE)
	g++ -c Globals.hpp Globals.cpp -I $(INCLUDE)
	g++ -c header.hpp header.cpp -I $(INCLUDE)
	g++ -c Button.hpp Button.cpp -I $(INCLUDE)
	g++ -c Textbox.hpp Textbox.cpp -I $(INCLUDE)
	g++ -c Queue.hpp Queue.cpp -I $(INCLUDE)
	g++ -c SLL.hpp SLL.cpp -I $(INCLUDE)
	g++ -c DLL.hpp DLL.cpp -I $(INCLUDE)
	g++ -c CLL.hpp CLL.cpp -I $(INCLUDE)
	g++ -c Image.hpp Image.cpp -I $(INCLUDE)
	g++ -c Stack.hpp Stack.cpp -I $(INCLUDE)
	g++ -c DataVisualization1.hpp DataVisualization1.cpp -I $(INCLUDE)
	g++ -c DataVisualization2.hpp DataVisualization2.cpp -I $(INCLUDE)
	g++ -c DataVisualization3.cpp DataVisualization3.hpp -I $(INCLUDE)
	g++ -c DataVisualization4.hpp DataVisualization4.cpp -I $(INCLUDE)
	g++ -c DataVisualization5.hpp DataVisualization5.cpp -I $(INCLUDE)
	g++ -c DataVisualization6.hpp DataVisualization6.cpp -I $(INCLUDE)
	g++ -c DataVisualization7.hpp DataVisualization7.cpp -I $(INCLUDE)

link:
	g++ $(CXXFLAGS) $(SOURCE).o header.o Button.o Image.o SLL.o DataVisualization3.o Textbox.o Globals.o DataVisualization1.o DataVisualization2.o DataVisualization4.o DLL.o DataVisualization5.o CLL.o Stack.o DataVisualization6.o Queue.o DataVisualization7.o -o main -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)

run:
	./${SOURCE}.exe
