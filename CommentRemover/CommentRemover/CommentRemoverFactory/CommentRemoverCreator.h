#pragma once
#include <memory>
#include "ICommentRemover.h"

enum Language
{
	cpp,
	python
};

class CommentRemoverCreator
{
public:
	static std::unique_ptr<ICommentRemover> Create(Language );
};

