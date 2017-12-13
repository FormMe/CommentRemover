#include "CommentRemoverCreator.h"


std::unique_ptr<ICommentRemover> CommentRemoverCreator::Create(Language lang)
{
	switch (lang)
	{
	case cpp:
		return std::make_unique<CppCommentRemover>();
	case python:
		throw std::invalid_argument("Not implemented");
	default:
		throw std::invalid_argument("Unknown language");
	}
}
