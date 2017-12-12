#pragma once
#include <fstream>

class ICodeState;

class Context
{
public:
	Context(std::ifstream & input, std::ofstream & output);

	void set_state(ICodeState* state);
	void handle();
	std::ifstream& getInputStream();
	std::ofstream& getOutputStream();

private:
	std::ifstream &input;
	std::ofstream &output;
	ICodeState *_state;
};

class ICodeState
{
public:
	virtual void handle(Context *) = 0;
};

class PureCode : public ICodeState
{
public:
	void handle(Context *) override;
};

class CommentStart : public ICodeState
{
public:
	void handle(Context *) override;
};

class OneLineComment : public ICodeState
{
public:
	void handle(Context *) override;
};

class MultLineComment : public ICodeState
{
public:
	void handle(Context *) override;
};