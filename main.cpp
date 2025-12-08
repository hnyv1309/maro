#include"utils.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void loopMode();

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
