#include "ArgvParser.h"


ArgvParser::ArgvParser()
{
}

ArgvParser::~ArgvParser()
{
}

void ArgvParser::Parse(int argc, char * argv[])
{
	if (argc != 4) throw std::invalid_argument("Invalid arguments count");

	langMap["-cpp"] = 0;
	langMap["-python"] = 1;
	auto it = langMap.find(argv[1]);
	if (it == langMap.end())
		throw std::invalid_argument("Unknown language");
	lang = (Language)it->second;

	inputStream.open(argv[2]);
	outputStream.open(argv[3]);
}

std::ifstream & ArgvParser::getInputStream()
{
	return inputStream;
}

std::ofstream & ArgvParser::getOutputStream()
{
	return outputStream;
}
