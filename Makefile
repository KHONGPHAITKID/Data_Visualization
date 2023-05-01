# This is makefile for SFML C++

path = D:\SFML-2.5.1
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
CXXFLAGS = -O2
SFMLFLAGS =
SOURCE = main
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system -lcomdlg32

#=======================================================================================#

all: compile link run

compile:
	g++ -c Globals.hpp Globals.cpp -I $(INCLUDE)
	g++ -c header.hpp header.cpp -I $(INCLUDE)
	g++ -c Button.hpp Button.cpp -I $(INCLUDE)
	g++ -c Textbox.hpp Textbox.cpp -I $(INCLUDE)
	g++ -c Image.hpp Image.cpp -I $(INCLUDE)
	g++ -c DropDownBox.hpp DropDownBox.cpp -I $(INCLUDE)
	g++ -c SLL.hpp SLL.cpp -I $(INCLUDE)
	g++ -c DLL.hpp DLL.cpp -I $(INCLUDE)
	g++ -c CLL.hpp CLL.cpp -I $(INCLUDE)
	g++ -c Stack.hpp Stack.cpp -I $(INCLUDE)
	g++ -c Queue.hpp Queue.cpp -I $(INCLUDE)
	g++ -c DataVisualization1.hpp DataVisualization1.cpp -I $(INCLUDE)
	g++ -c DataVisualization2.hpp DataVisualization2.cpp -I $(INCLUDE)
	g++ -c DataVisualization3.hpp DataVisualization3.cpp -I $(INCLUDE)
	g++ -c DataVisualization4.hpp DataVisualization4.cpp -I $(INCLUDE)
	g++ -c DataVisualization5.hpp DataVisualization5.cpp -I $(INCLUDE)
	g++ -c DataVisualization6.hpp DataVisualization6.cpp -I $(INCLUDE)
	g++ -c DataVisualization7.hpp DataVisualization7.cpp -I $(INCLUDE)
	g++ -c $(SOURCE).cpp -I $(INCLUDE)
link:
	g++ $(CXXFLAGS) $(SOURCE).o Globals.o header.o Button.o Textbox.o Image.o DropDownBox.o SLL.o DLL.o CLL.o Stack.o Queue.o DataVisualization1.o DataVisualization2.o DataVisualization3.o DataVisualization4.o DataVisualization5.o DataVisualization6.o DataVisualization7.o -o main -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)

run:
	./${SOURCE}.exe
