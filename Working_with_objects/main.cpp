#include "RootClass.h"

/**
*	Global function which is start of program. This function is called at program startup after initialization of the non-local objects
*
*	@param argc - number of arguments passed to the program from the environment
*	@param argv - pointer to array of pointers to multibyte strings that represent the arguments passed to the program
*
*	@return exit code
*/
int main(int argc, char* argv[])
{
	RootClass root(nullptr);
	root.start();
	root.app();
	
	return 0;
}
