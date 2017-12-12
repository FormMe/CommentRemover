#include "CommentRemoverCreator.h"


ICommentRemover * CommentRemoverCreator::Create(Language lang)
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
