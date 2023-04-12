# Makefile for C++ SFML

build: compile
	g++ main.o -o main.exe -L "SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
compile:
	g++ -c game.cpp -I "SFML-2.5.1\include"
	g++ -c main.cpp -I "SFML-2.5.1\include"