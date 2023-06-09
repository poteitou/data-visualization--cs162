# Makefile for C++ SFML 2.5.1

build: compile
	g++ *.o -o main.exe -L "SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
compile:
	g++ -c datastruct/*.cpp -I "SFML-2.5.1\include"
	g++ -c interface/*.cpp -I "SFML-2.5.1\include"
	g++ -c main.cpp -I "SFML-2.5.1\include"