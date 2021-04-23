#ifndef THIRDCLASS_H
#define THIRDCLASS_H

#include "BaseClass.h"

/*Successor class, inherits base class*/
class ThirdClass : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 
};

#endif