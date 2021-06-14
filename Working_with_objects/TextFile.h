#ifndef TEXTFILE_H
#define TEXTFILE_H
#include "BaseClass.h"
#include <sstream>
#include <fstream>
#include <cctype>

/*Successor class, inherits base class*/
class TextFile : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 

	/**
	* Initializes constructor of base class with one parameter
	*
	* @param parent - pointer to parent object
	*/
	TextFile(BaseClass* parent) : BaseClass(parent) {};

	/**
	* Builds hierarchical object tree and sets connection between 'sender' object and 'target' object
	*/
	void start();

	/**
	* Starts algorithm to input coordinates and symbol and insert it to text file, at the end method calls method to print content of text file
	*/
	void app();

	/**
	* Creates new text file and sets name for it, writes numeric 10x10 matrix of number 8 to file
	*
	* @param file_name - name of file
	*/
	void createTextFile(std::string file_name);

	/**
	* Sets connection between two objects
	*
	* @note This method uses methods to get pointers to signal and handler methods
	*/
	void Connection();
};

#endif