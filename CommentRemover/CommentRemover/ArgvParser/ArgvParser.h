#pragma once
#include <map>
#include <string>

#include "..\CommentRemoverFactory\CommentRemoverCreator.h"

class ArgvParser
{
public:
	void Parse(int argc, char* argv[]);

	Language lang;
	std::ifstream& getInputStream();
	std::ofstream& getOutputStream();
private:
	std::map <std::string, int> langMap;
	std::ifstream inputStream;
	std::ofstream outputStream;
};