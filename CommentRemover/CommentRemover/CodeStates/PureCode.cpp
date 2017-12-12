#include "../Context/Context.h"

void PureCode::handle(Context *context)
{
	auto &input = context->getInputStream();
	auto &output = context->getOutputStream();

	char cf, cs;
	while (!input.eof())
	{
		cf = input.get();
		if (cf == '/')
		{
			cs = input.get();
			if (cs == EOF)
			{
				output.put(cf);
				break;
			}
			switch (cs)
			{
			case '/':
				context->set_state(new OneLineComment());
				return;
			case '*':
				context->set_state(new MultLineComment());
				return;
			default:
				output.put(cf);
				output.put(cs);
				break;
			}
		}
		else
		{
			output.put(cf);
		}
	}
	context->set_state(nullptr);
}