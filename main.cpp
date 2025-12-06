#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>
using namespace std;

enum LoopFlag {
		LF_UNDEFINED,
		LF_EXIT,
		LF_SUCCESS
};

void loopMode();

void printUsage(){
		cout << "usage" << endl;
}

void printTmuxWorkspaces(){
		cout << "tmux workspaces" << endl;
}

void stringifyArgs(char** argv, int argc, vector<string>& args){
		for (int i = 0; i < argc; i++){
				args.push_back(string(argv[i]));
		}
}

bool isWhiteSpace(char a){
		return (a == ' ' || a == '\t');
}

void stringSplit(string target, vector<string>& output){
		string current;
		for (auto i = 0; i < target.length(); i++){
				bool white = isWhiteSpace(target[i]);
				if (white && !current.empty()){
						output.push_back(current);
						current.clear();
				} else { 
						if (!white) current.push_back(target[i]);
				}
		}

		if (!current.empty()) output.push_back(current);
}

// multiple shell environments not implemented
bool executeAbbrCommand(char c){
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

LoopFlag excuteLoop(vector<string> tokens){
		auto length = tokens.size();
		if (length == 1){
				if (tokens[0] == "help" || tokens[0] == "h"){
						printUsage();
						return LF_SUCCESS;
				} else if (tokens[0] == "exit" || tokens[0] == "ex"){
						return LF_EXIT;
				}
		} else if (length == 2){
				if (tokens[0] == "t"){
						if (tokens[1] == "-l"){
								printTmuxWorkspaces();
								return LF_SUCCESS;
						}
						else if (tokens[1] == "a"){
								cout << "Workspaces `learning` loaded" << endl;
								system("source workspaces/a.sh");
								return LF_SUCCESS;
						}
						else if (tokens[1] == "b"){
								cout << "Workspaces `stem` loaded" << endl;
								system("source workspaces/b.sh");
								return LF_SUCCESS;
						}
				}
		}else{
				for (string token : tokens) cout << token << endl;
				return LF_UNDEFINED;
		}
		return LF_UNDEFINED;
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
				getline(cin >> ws, command);
				stringSplit(command, tokens);

				LoopFlag flag = excuteLoop(tokens);
				if (flag == LF_UNDEFINED){
						cout << "undefined command" << endl;
				} else if (flag == LF_EXIT){
						break;
				}
				else if (flag != LF_SUCCESS){
						cout << "undefined flag" << flag << endl;
				}

				tokens.clear();
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
