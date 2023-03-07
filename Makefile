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
	g++ -c $(SOURCE).cpp header.hpp header.cpp -I $(INCLUDE)
link:
	g++ $(CXXFLAGS) $(SOURCE).o header.o -o main -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
run:
	./${SOURCE}.exe
