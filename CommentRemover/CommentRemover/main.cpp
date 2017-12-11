#include "ArgvParser.h"

int	main(int argc, char* argv[])
{
	ArgvParser cmdParams;
	cmdParams.Parse(argc, argv);
	auto remover = CommentRemoverCreator::Create(cmdParams.lang);
	remover->remove(cmdParams.getInputStream(),
					cmdParams.getOutputStream());

	return 0;
}