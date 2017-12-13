#include "../Context.h"

void PureCode::handle(Context &context)
{
	auto &input = context.getInputStream();
	auto &output = context.getOutputStream();

	char cf, cs;
	while (!input.eof())
	{
		cf = input.get();
		if (cf == '/')
		{
			cs = input.get();
			switch (cs)
			{
			case '/':
				context.set_state(std::make_unique<SingleLineComment>());
				return;
			case '*':
				context.set_state(std::make_unique<MultLineComment>());
				return;
			case '\'':
				context.set_state(std::make_unique<SingleQuote>());
				return;
			case '\"':
				context.set_state(std::make_unique<DoubleQuote>());
				return;
			default:
				output.put(cf);
				if (cs != EOF) output.put(cs);
				break;
			}
		}
		else
		{
			output.put(cf);
		}
	}
	context.set_state(nullptr);
}