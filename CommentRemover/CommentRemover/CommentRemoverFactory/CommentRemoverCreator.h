#pragma once
#include "ICommentRemover.h"
#include "CppCommentRemover.h"
enum Language
{
	cpp,
	python
};

class CommentRemoverCreator
{
public:
	CommentRemoverCreator();
	~CommentRemoverCreator();

	static ICommentRemover* Create(Language lang)
	{
		switch (lang)
		{
		case cpp:
			return new CppCommentRemover();
		case python:
			break;
		default:
			throw std::invalid_argument("Unknown language");
		}
	}
};

