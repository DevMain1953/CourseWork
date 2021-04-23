#ifndef FOURTHCLASS_H
#define FOURTHCLASS_H

#include "BaseClass.h"

/*Successor class, inherits base class*/
class FourthClass : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 
};

#endif