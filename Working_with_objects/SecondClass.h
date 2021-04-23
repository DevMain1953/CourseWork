#ifndef SECONDCLASS_H
#define SECONDCLASS_H

#include "BaseClass.h"

/*Successor class, inherits base class*/
class SecondClass : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 
};

#endif