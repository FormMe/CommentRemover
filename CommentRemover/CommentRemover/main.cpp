#include <iostream>

#include "ArgvParser/ArgvParser.h"

int	main(int argc, char* argv[])
{
	try
	{
		ArgvParser cmdParams;
		cmdParams.Parse(argc, argv);
		auto remover = CommentRemoverCreator::Create(cmdParams.lang);
		remover->remove(cmdParams.getInputStream(),
			cmdParams.getOutputStream());
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what();
	}

	return 0;
}