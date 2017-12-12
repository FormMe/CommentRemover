#include "../Context/Context.h"


void OneLineComment::handle(Context *context)
{
	auto &input = context->getInputStream();
	auto &output = context->getOutputStream();

	char c;
	while (!input.eof())
	{
		c = input.get();
		if (c == '\n')
		{
			context->set_state(new PureCode());
			output.put(c);
			return;
		}
	}
	context->set_state(nullptr);
}