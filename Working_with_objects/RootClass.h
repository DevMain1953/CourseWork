#ifndef ROOTCLASS_H
#define ROOTCLASS_H

#include "BaseClass.h"

/*This class realizes root object in hierarchical object tree, here are methods to set data and construct tree*/
class RootClass : public BaseClass
{
protected:
	struct connection_struct
	{
		std::string object;
		int number;
		std::string object1;
	};
	std::vector<connection_struct*> connects;

public:
	using BaseClass::BaseClass; //Using members of base class 

	/**
	*	Initializes constructor of BaseClass with one parameter
	*
	*	@param parent - pointer to parent object
	*/
	RootClass(BaseClass* parent) : BaseClass(parent) {};

	/**
	*	Removes array of pointers to structure with connection number, and object names
	*/
	~RootClass();

	/**
	*	Starts algorithm of setting data from keyboard for hierarchical tree construction
	*
	*	@note Algorithm is almost same as in previous task, all 5 classes was used
	*/
	void start();

	/**
	*	Calls method to print hierarchical object tree and methods to print and emit signal
	*
	*	@note This method prints "Object tree" before calling method to print hierarchical object tree
	*/
	void app();

	/**
	*	Finds objects in hierarchical tree using their coordinates then prints search result (object found or not found)
	*/
	void findObjectFromCoordinate();

	/**
	*	Sets connections between objects
	*
	*	@note This method uses methods to get pointers to signal and handler methods
	*/
	void Connections();

	/**
	*	Prints connections from array of connections
	*/
	void printConnects();

	/**
	*	Emits signal, uses BaseClass method to send signal
	*/
	void emitSignal();

	/**
	*	Builds a message text
	*
	*	@param text - reference to string to build message
	*/
	void Signal(std::string& text);

	/**
	*	Prints a message
	*
	*	@param text - message to print
	*/
	void Handler(std::string text);

	/**
	*	Returns pointer to signal method that is casted to pointer to BaseClass method
	*
	*	@param number - class number
	*
	*	@return pointer to signal method that is casted to pointer to BaseClass method
	*/
	TYPE_SIGNAL getSignal(int number);

	/**
	*	Returns pointer to handler method that is casted to pointer to BaseClass method
	*
	*	@param number - class number
	*
	*	@return pointer to handler method that is casted to pointer to BaseClass method
	*/
	TYPE_HANDLER getHandler(int number);
};
#endif
