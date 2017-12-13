#include "Context.h"


Context::Context(std::ifstream & inputStream, std::ofstream & outputStream) :
	input(inputStream),
	output(outputStream),
	_state(std::make_unique<PureCode>()) {}

void Context::set_state(std::unique_ptr<ICodeState> state)
{
	_state = std::move(state);
}

void Context::handle()
{
	while (_state) _state->handle(*this);
}

std::ifstream & Context::getInputStream()
{
	return input;
}

std::ofstream & Context::getOutputStream()
{
	return output;
}
