#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void printUsage(){
		cout << "usage" << endl;
}

void stringifyArgs(char** argv, int argc, vector<string>& args){
		for (int i = 0; i < argc; i++){
				args.push_back(string(argv[i]));
		}
}

// multiple shell environments not implemented
bool executeCommand(char c){
		switch(c){
				case 'l':
						system("ls");
						return true;
				case 'g':
						system("git log");
						return true;
				case 'p':
						system("pwd");
						return true;
				case 'h':
						printUsage();
						return true;
				default:
						return false;
		}
}

void executeAbbrCommands(string commands){
		for (char command : commands) {
				if (!executeCommand(command)) {
						cout << "error: invalid command `" << command << "`" << endl;
				}
		}
}

void loopMode(){
		string command;
		while (true){
				cout << "> ";
				getline(cin >> ws, command);
				if (command == "help" || command == "h"){
						printUsage();
				} else if (command == "exit" || command == "ex"){
						break;
				}
				else {
						cout << command << endl;
				}
		}
}

int main(int argc, char** argv){
		vector<string> args;
		stringifyArgs(argv, argc, args);

		if (argc == 1) {
				printUsage(); return 0;
		} else if (argc == 2){
				if (args[1] == "-m"){
						loopMode();
				} else {
						string abbrCommands(argv[1]);
						executeAbbrCommands(abbrCommands);
				}
		} else {
				cout << "ERROR: Invalid command" << endl;
				return 1;
		}

		return 0;
}
