#pragma once
#include <fstream>

class ICommentRemover
{
public:
	ICommentRemover() {};
	~ICommentRemover() {};

	virtual void remove(std::ifstream & input, std::ofstream & output) = 0;
};

class CppCommentRemover :
	public ICommentRemover
{
public:
	void remove(std::ifstream & input, std::ofstream & output) override;
};