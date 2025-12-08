#pragma once
#include<vector>
#include<string>

using namespace std;

enum LoopFlag {
		LF_UNDEFINED,
		LF_EXIT,
		LF_SUCCESS
};


// void printUsage();
// void printTmuxWorkspaces();
void printFile();
void stringifyArgs(char** argv, int argc, vector<string>& args);
bool isWhiteSpace(char a);
void stringSplit(string target, vector<string>& output);
bool executeAbbrCommand(char c);
LoopFlag excuteLoop(vector<string> tokens);
void executeAbbrCommands(string commands);
void loopMode();
