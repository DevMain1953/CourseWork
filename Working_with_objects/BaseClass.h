#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>
#include <vector>
#include <string>

/*Base class describes hierarchical object tree*/
class BaseClass
{
protected:
	std::string name; //Object name
	BaseClass* parent; //Pointer to parent object
	int ready; //Object ready state
	std::vector<BaseClass*> children; //Vector (array) of subordinate objects

public:
	/**
	*	Creates object in the hierarchy, if parent object exists, creates subordinate object
	*
	*	@param parent - pointer to parent object
	*/
	BaseClass(BaseClass* parent);

	/**
	*	Creates object in the hierarchy, if parent object exists, creates subordinate object and sets name to it
	*
	*	@param parent - pointer to parent object
	*	@param name - object name
	*/
	BaseClass(BaseClass* parent, std::string name);

	/**
	*	Removes subordinate objects
	*/
	~BaseClass();

	/**
	*	Sets ready state to the object
	*
	*	@param ready - ready state
	*/
	void setReady(int ready);

	/**
	*	Returns object name
	*
	*	@return object name
	*/
	std::string getName();

	/**
	*	Sets name to the object
	*
	*	@param name - object name
	*/
	void setName(std::string name);

	/**
	*	Returns pointer to object in hierarchical tree
	*
	*	@param name - object name to find
	*	@note This method uses recursive call through pointer in array of subordinate objects
	*
	*	@return pointer to object in hierarchical tree
	*/
	BaseClass* getObjectFromName(std::string name);

	/**
	*	Prints objects and their ready state
	*
	*	@note This method uses recursive call through pointer in array of subordinate objects
	*/
	void show();

	/**
	*	Prints hierarchical tree
	*
	*	@param parent - pointer to parent object
	*	@param space - number of spaces in hierarchical tree before branch
	*	@note This method uses recursive call through pointer in array of subordinate objects
	*/
	void printTree(BaseClass* parent, int space);

};

#endif
