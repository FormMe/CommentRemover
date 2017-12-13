#include "../Context.h"


void MultLineComment::handle(Context &context)
{
	auto &input = context.getInputStream();
	auto &output = context.getOutputStream();

	int innerCommentCount = 0;
	char cf, cs;
	while (!input.eof())
	{
		cf = input.get();
		if (cf == '*')
		{
			cs = input.get();
			if (cs == '/')
			{
				context.set_state(std::make_unique<PureCode>());
				return;
			}
		}
	}
	context.set_state(nullptr);
}