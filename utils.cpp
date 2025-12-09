#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include"./utils.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

void printFile(const char* fileName){
		ifstream file(fileName);
		if (!file) {
				cerr << "Invalid file name: `" << fileName << "`\n";
				exit(1);
		}
		string line;
		while (getline(file >> std::ws, line)) cout << line << endl;
}

void stringifyArgs(char** argv, int argc, vector<string>& args){
		args.reserve(argc);
		for (int i = 0; i < argc; i++){
				args.push_back(string(argv[i]));
		}
}

bool isWhiteSpace(char a){
		return (a == ' ' || a == '\t');
}

void stringSplit(const string& target, vector<string>& output){
		string current;
		for (char c : target){
				bool white = isWhiteSpace(c);
				if (white){
						if (!current.empty()){
								output.push_back(current);
								current.clear();
						}
				}
				else current.push_back(c);
		}

		if (!current.empty()) output.push_back(current);
}

// multiple shell environments not implemented
bool executeAbbrCommand(char c){
		switch(c){
				case 'l': system("ls"); return true;
				case 'g': system("git log"); return true;
				case 'p': system("pwd"); return true;

				case 'h':
						printFile(USAGE_FILE_PATH);
						return true;

				case 'm':
						loopMode();
						return true;

				case 'a':
						cout << "Workspaces `learning` loaded" << endl;
						system("source workspaces/a.sh");
						return true;

				case 'b':
						cout << "Workspaces `stem` loaded" << endl;
						system("source workspaces/a.sh");
						return true;

				default:
						return false;
		}
}

LoopFlag executeLoop(const vector<string> &tokens){
		auto length = tokens.size();
		if (length == 1){
				if (tokens[0] == "help" || tokens[0] == "h"){
						printFile(USAGE_FILE_PATH);
						return LoopFlag::SUCCESS;
				} else if (tokens[0] == "exit" || tokens[0] == "ex"){
						return LoopFlag::EXIT;
				}
		} 

		else if (length == 2){
				if (tokens[0] == "t"){
						if (tokens[1] == "-l"){
								printFile(WORKSPACE_FILE_PATH);
								return LoopFlag::SUCCESS;
						}
						else if (tokens[1] == "a"){
								cout << "Workspaces `learning` loaded" << endl;
								system("source workspaces/a.sh");
								return LoopFlag::SUCCESS;
						}
						else if (tokens[1] == "b"){
								cout << "Workspaces `stem` loaded" << endl;
								system("source workspaces/b.sh");
								return LoopFlag::SUCCESS;
						}
				}
		}

		else{
				for (string token : tokens) cout << token << endl;
				return LoopFlag::UNDEFINED;
		}

		return LoopFlag::UNDEFINED;
}

void executeAbbrCommands(string commands){
		for (char command : commands) {
				if (!executeAbbrCommand(command)) {
						cout << "error: invalid command `" << command << "`" << endl;
				}
		}
}

void loopMode(){
		string command;
		vector<string> tokens;

		while (true){
				cout << "> ";
				getline(cin >> std::ws, command);

				tokens.clear();
				stringSplit(command, tokens);

				LoopFlag flag = executeLoop(tokens);

				if (flag == LoopFlag::UNDEFINED){
						cout << "undefined command" << endl;
				} else if (flag == LoopFlag::EXIT){
						break;
				}
				else if (flag != LoopFlag::SUCCESS){
						cout << "undefined flag" << static_cast<int>(flag) << endl;
				}
		}
}

