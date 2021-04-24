#include "FirstClass.h"
#include "SecondClass.h"
#include "ThirdClass.h"
#include "FourthClass.h"
#include "FifthClass.h"
#include "RootClass.h"

void RootClass::start()
{
	std::string root_name, parent_name, class_name;
	int number, ready;
	BaseClass* parent;
	BaseClass* obj = nullptr;

	std::cin >> root_name;
	this->setName(root_name);
	this->setReady(1);
	std::cin >> parent_name;

	while (parent_name != "endtree")
	{
		std::cin >> class_name >> number >> ready;
		parent = this->find(parent_name);
		if (number == 2)
		{
			obj = new FirstClass(parent, class_name);
			obj->setReady(ready);
		}
		if (number == 3)
		{
			obj = new SecondClass(parent, class_name);
			obj->setReady(ready);
		}
		if (number == 4)
		{
			obj = new ThirdClass(parent, class_name);
			obj->setReady(ready);
		}
		if (number == 5)
		{
			obj = new FourthClass(parent, class_name);
			obj->setReady(ready);
		}
		if (number == 6)
		{
			obj = new FifthClass(parent, class_name);
			obj->setReady(ready);
		}
		else
		{
			obj = nullptr;
		}
		std::cin >> parent_name;
	}
}

void RootClass::showTree()
{
	std::cout << "Object tree" << std::endl;
	this->printTree(this, 0);
}