all:
	g++ -std=c++23 -Wpedantic -Wall main.cpp utils.cpp -o main && ./main $A
