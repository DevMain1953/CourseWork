#ifndef FILEPRINTER_H
#define FILEPRINTER_H
#include "BaseClass.h"
#include <fstream>

/*Successor class, inherits base class*/
class FilePrinter : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 

	/**
	* Returns string that contains all data from text file
	*
	* @param file_name - name of file to open
	* @return string that contains all data from text file
	*/
	std::string readTextFile(std::string file_name);

	/**
	* Prints content from text file to output stream
	*
	* @param file_name - name of file to open and read
	*/
	void printFileContent(std::string file_name);

};

#endif