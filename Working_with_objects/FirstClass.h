#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H

#include "BaseClass.h"

/*Successor class, inherits base class*/
class FirstClass : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 

	/**
	*	Starts algorithm of setting data and hierarchical tree construction
	*/
	void start();

	/**
	*	Prints result, calls 'show' method
	*/
	void printResults();

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