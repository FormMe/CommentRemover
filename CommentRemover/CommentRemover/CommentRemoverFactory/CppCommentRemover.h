#pragma once
#include "ICommentRemover.h"
class CppCommentRemover :
	public ICommentRemover
{
public:
	CppCommentRemover();
	~CppCommentRemover();

	void remove(std::ifstream & input, std::ofstream & output);
};

