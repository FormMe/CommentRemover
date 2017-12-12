#include "Context.h"


Context::Context(std::ifstream & inputStream, std::ofstream & outputStream) :
	input(inputStream),
	output(outputStream),
	_state(new PureCode()) {}

void Context::set_state(ICodeState* state)
{
	_state = state;
}

void Context::handle()
{
	while (_state) _state->handle(this);
}

std::ifstream & Context::getInputStream()
{
	return input;
}

std::ofstream & Context::getOutputStream()
{
	return output;
}
