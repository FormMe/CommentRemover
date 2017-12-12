#include "ICommentRemover.h"
#include "../Context/Context.h"

void CppCommentRemover::remove(std::ifstream &input, std::ofstream &output)
{
	Context c(input, output);
	c.handle();
}