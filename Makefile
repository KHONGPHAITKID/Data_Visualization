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
	g++ -c Components/Button.hpp Components/Button.cpp -I $(INCLUDE)
	g++ -c Components/Textbox.hpp Components/Textbox.cpp -I $(INCLUDE) 
	g++ -c Components/Image.hpp Components/Image.cpp -I $(INCLUDE) 
	g++ -c Components/DropDownBox.hpp Components/DropDownBox.cpp -I $(INCLUDE) 
	g++ -c Components/SLL.hpp Components/SLL.cpp -I $(INCLUDE) 
	g++ -c Components/DLL.hpp Components/DLL.cpp -I $(INCLUDE) 
	g++ -c Components/CLL.hpp Components/CLL.cpp -I $(INCLUDE) 
	g++ -c Components/Stack.hpp Components/Stack.cpp -I $(INCLUDE) 
	g++ -c Components/Queue.hpp Components/Queue.cpp -I $(INCLUDE) 
	g++ -c Pages/DataVisualization1.hpp Pages/DataVisualization1.cpp -I $(INCLUDE)
	g++ -c Pages/DataVisualization2.hpp Pages/DataVisualization2.cpp -I $(INCLUDE)
	g++ -c Pages/DataVisualization3.hpp Pages/DataVisualization3.cpp -I $(INCLUDE)
	g++ -c Pages/DataVisualization4.hpp Pages/DataVisualization4.cpp -I $(INCLUDE)
	g++ -c Pages/DataVisualization5.hpp Pages/DataVisualization5.cpp -I $(INCLUDE)
	g++ -c Pages/DataVisualization6.hpp Pages/DataVisualization6.cpp -I $(INCLUDE)
	g++ -c Pages/DataVisualization7.hpp Pages/DataVisualization7.cpp -I $(INCLUDE)
	g++ -c $(SOURCE).cpp -I $(INCLUDE)
link:
	g++ $(CXXFLAGS) $(SOURCE).o Globals.o header.o Button.o Textbox.o Image.o DropDownBox.o SLL.o DLL.o CLL.o Stack.o Queue.o DataVisualization1.o DataVisualization2.o DataVisualization3.o DataVisualization4.o DataVisualization5.o DataVisualization6.o DataVisualization7.o -o main -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
run:
	./${SOURCE}.exe
