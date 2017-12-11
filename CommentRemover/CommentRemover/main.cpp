#include "CommentRemoverFactory\CommentRemoverCreator.h"

int	main(int argc, char* argv[])
{
	auto remover = CommentRemoverCreator::Create(Language::cpp);
	std::ifstream inputStream(argv[2]);
	std::ofstream outputStream(argv[3]);
	remover->remove(inputStream, outputStream);
	return 0;
}