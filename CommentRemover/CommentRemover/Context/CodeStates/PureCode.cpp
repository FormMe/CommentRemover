#include "../Context.h"

void PureCode::handle(Context &context)
{
	auto &input = context.getInputStream();
	auto &output = context.getOutputStream();

	char cf, cs;
	while (!input.eof())
	{
		cf = input.get();
		switch (cf)
		{
		case '/':
			cs = input.get();
			switch (cs)
			{
			case '/':
				context.set_state(std::make_unique<SingleLineComment>());
				return;
			case '*':
				context.set_state(std::make_unique<MultLineComment>());
				return;
			default:
				output.put(cf);
				if (cs != EOF) output.put(cs);
				break;
			}
			break;

		case '\'':
			context.set_state(std::make_unique<SingleQuote>());
			output.put(cf);
			return;
		case '\"':
			context.set_state(std::make_unique<DoubleQuote>());
			output.put(cf);
			return;
		default:
			output.put(cf);
			break;
		}
	}
	context.set_state(nullptr);
}