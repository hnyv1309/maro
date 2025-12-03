#include<iostream>
#include<cstdlib>
#include<fstream>
using std::cout;
using std::endl;

void usage(){
		cout << "usage" << endl;
}

void executeAbbrCommands(std::string commands){
		for (char command : commands) {
				switch (command){
						case 'l':
								system("ls");
								break;
						case 'g':
								system("git log");
								break;
						case 'p':
								system("pwd");
								break;
						default:
								cout << "unimplemented commnand `" << command << "`" << endl;
								break;
				}
		}
}

int main(int argc, char** argv){
		if (argc == 1) {
				usage(); return 0;
		} else if (argc == 2){
				std::string abbrCommands(argv[1]);
				executeAbbrCommands(abbrCommands);
		} else {
				cout << "ERROR: Invalid command" << endl;
				return 1;
		}
		return 0;
}
