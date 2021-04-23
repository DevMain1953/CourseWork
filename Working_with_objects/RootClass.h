#ifndef ROOTCLASS_H
#define ROOTCLASS_H

#include "BaseClass.h"

/*This class realizes root object in hierarchical object tree, here are methods to set data and construct tree*/
class RootClass : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 

	/**
	*	Starts algorithm of setting data for hierarchical tree construction
	*
	*	@note Algorithm is almost same as in previous task, all 5 classes was used
	*/
	void start();

	/**
	*	Calls method to construct hierarchical object tree
	*
	*	@note This method prints "Object tree" before calling method to construct hierarchical object tree
	*/
	void showTree();
};
#endif
