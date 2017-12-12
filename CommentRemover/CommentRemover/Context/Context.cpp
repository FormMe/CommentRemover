#include "Context.h"


Context::Context(std::ifstream & inputStream,std::ofstream & outputStream) :
	_state(new PureCodeState(this)),
	input(inputStream),
	output(outputStream)
{}

void Context::set_state(ICodeState* state)
{
	_state = state;
}

void Context::handle()
{
	_state->handle();
}

std::ifstream & Context::getInputStream()
{
	return input;
}

std::ofstream & Context::getOutputStream()
{
	return output;
}
