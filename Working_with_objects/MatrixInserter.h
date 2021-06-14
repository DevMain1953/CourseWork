#ifndef MATRIXINSERTER_H
#define MATRIXINSERTER_H
#include "BaseClass.h"
#include <sstream>
#include <fstream>
#include <cctype>

/*Successor class, inherits base class*/
class MatrixInserter : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 

	/**
	* Returns true if symbol is from latin alphabet, false otherwise
	*
	* @param symbol - symbol to check
	* @return true if symbol is from latin alphabet, false otherwise
	*/
	bool isLatin(char symbol);

	/**
	* Performs inserting new symbol to text file, if message contains symbol that is not from latin alphabet, method inserts error message to the end of file
	*
	* @param message - message that contains new symbol and position of inserting
	*/
	void Handler(std::string message);

	/**
	* Returns pointer to handler method converted to type of pointer to base class method
	*
	* @return pointer to handler method converted to type of pointer to base class method
	*/
	static TYPE_HANDLER getHandler();

	/**
	* Returns string from text file that contains matrix 10x10
	*
	* @param file_name - name of file to open
	* @return string from text file that contains matrix 10x10
	*/
	std::string readMatrixFromTextFile(std::string file_name);

	/**
	* Returns string that contains all data from text file
	*
	* @param file_name - name of file to open
	* @return string that contains all data from text file
	*/
	std::string readTextFile(std::string file_name);
};

#endif