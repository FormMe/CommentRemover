#include "../Context.h"


void MultLineComment::handle(Context *context)
{
	auto &input = context->getInputStream();
	auto &output = context->getOutputStream();

	int innerCommentCount = 0;
	char cf, cs;
	while (!input.eof())
	{
		cf = input.get();
		cs = input.get();
		if (cf == '/' && cs == '*')
		{
			innerCommentCount++;
			continue;
		}
		if (cf == '*' && cs == '/')
		{
			if (innerCommentCount == 0)
			{
				context->set_state(new PureCode());
				return;
			}
			else
			{
				innerCommentCount--;
				continue;
			}
		}
	}
	context->set_state(nullptr);
}