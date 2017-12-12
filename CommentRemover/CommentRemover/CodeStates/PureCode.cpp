#include "../Context/Context.h"

PureCode::PureCode()
{
}

void PureCode::handle(Context *context)
{
	auto &input = context->getInputStream();
	auto &output = context->getOutputStream();

	auto c = input.get();
	while (!input.eof())
	{
		output.put(c);
	}
}