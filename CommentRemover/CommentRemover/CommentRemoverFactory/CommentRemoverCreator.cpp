#include "CommentRemoverCreator.h"


ICommentRemover * CommentRemoverCreator::Create(Language lang)
{
	switch (lang)
	{
	case cpp:
		return new CppCommentRemover();
	case python:
		throw std::invalid_argument("Not implemented");
	default:
		throw std::invalid_argument("Unknown language");
	}
}
