#pragma once
#include<vector>
#include<string>
#include<cstdint>

inline constexpr const char* USAGE_FILE_PATH = "./doc/usage.txt";
inline constexpr const char* WORKSPACE_FILE_PATH = "./doc/workspaces.txt";

enum class LoopFlag : uint8_t {
		UNDEFINED,
		EXIT,
		SUCCESS
};


void printFile(const char* fileName);
void stringifyArgs(char** argv, int argc, std::vector<std::string>& args);
bool isWhiteSpace(char c);
void stringSplit(const std::string &target, std::vector<std::string>& output);
bool executeAbbrCommand(char c);
LoopFlag executeLoop(const std::vector<std::string> &tokens);
void executeAbbrCommands(std::string commands);
void loopMode();
