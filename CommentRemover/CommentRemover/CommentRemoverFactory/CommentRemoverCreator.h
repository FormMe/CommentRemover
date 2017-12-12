#pragma once
#include "ICommentRemover.h"

enum Language
{
	cpp,
	python
};

class CommentRemoverCreator
{
public:
	static ICommentRemover* Create(Language );
};

