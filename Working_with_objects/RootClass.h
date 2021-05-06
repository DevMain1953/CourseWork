#ifndef ROOTCLASS_H
#define ROOTCLASS_H

#include "BaseClass.h"

/*This class realizes root object in hierarchical object tree, here are methods to set data and construct tree*/
class RootClass : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 

	/**
	*	Starts algorithm of setting data from keyboard for hierarchical tree construction
	*
	*	@note Algorithm is almost same as in previous task, all 5 classes was used
	*/
	void start();

	/**
	*	Calls method to print hierarchical object tree, calls method to find object using its coordinate in tree (findObjectFromCoordinate)
	*
	*	@note This method prints "Object tree" before calling method to print hierarchical object tree
	*/
	void showTree();

	/**
	*	Finds objects in hierarchical tree using their coordinates then prints search result (object found or not found)
	*
	*	@note This method prints "Object tree" before calling method to print hierarchical object tree
	*/
	void findObjectFromCoordinate();
};
#endif
