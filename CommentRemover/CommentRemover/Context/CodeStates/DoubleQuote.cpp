#include "../Context.h"

void DoubleQuote::handle(Context &context)
{
	auto &input = context.getInputStream();
	auto &output = context.getOutputStream();

	char c;
	while (!input.eof())
	{
		c = input.get();
		output.put(c);
		if (c == '"')
		{
			context.set_state(std::make_unique<PureCode>());
			return;
		}
	}
	context.set_state(nullptr);
}