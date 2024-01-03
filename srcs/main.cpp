#include "scop.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2){
		std::cerr << "./scop <filename>.obj" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		Scop::App app;

		app.run(argv[1]);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
