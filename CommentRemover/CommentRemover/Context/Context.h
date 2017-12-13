#pragma once
#include <fstream>
#include <memory>

class ICodeState;

class Context
{
public:
	Context(std::ifstream & input, std::ofstream & output);

	void set_state(std::unique_ptr<ICodeState> );
	void handle();
	std::ifstream& getInputStream();
	std::ofstream& getOutputStream();

private:
	std::ifstream &input;
	std::ofstream &output;
	std::unique_ptr<ICodeState> _state;
};

class ICodeState
{
public:
	virtual void handle(Context &) = 0;
};

class PureCode : public ICodeState
{
public:
	void handle(Context &) override;
};

class SingleQuote : public ICodeState
{
public:
	void handle(Context &) override;
};

class DoubleQuote : public ICodeState
{
public:
	void handle(Context &) override;
};

class SingleLineComment : public ICodeState
{
public:
	void handle(Context &) override;
};

class MultLineComment : public ICodeState
{
public:
	void handle(Context &) override;
};