#ifndef SECONDCLASS_H
#define SECONDCLASS_H

#include "BaseClass.h"

/*Successor class, inherits base class*/
class SecondClass : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 

	/**
	*	Builds a message text
	*
	*	@param text - reference to string to build message
	*/
	void Signal(std::string& text);

	/**
	*	Prints a message
	*
	*	@param text - a message to print
	*/
	void Handler(std::string text);
};

#endif