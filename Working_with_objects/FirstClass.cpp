#include "FirstClass.h"
#include "SecondClass.h"
#include "ThirdClass.h"
#include "FourthClass.h"

void FirstClass::start()
{
	std::string root, obj_name;
	int ready, class_number;
	std::cin >> root;
	name = root; //Using BaseClass field 'name'
	BaseClass* base;
	while (true)
	{
		std::cin >> root;
		if (root == "endtree")
		{
			break;
		}
		std::cin >> obj_name >> class_number >> ready;
		if (class_number == 2)
		{
			base = new SecondClass(getObjectFromName(root), obj_name);
			base->setReady(ready);
		}
		else if (class_number == 3)
		{
			base = new ThirdClass(getObjectFromName(root), obj_name);
			base->setReady(ready);
		}
		else
		{
			base = new FourthClass(getObjectFromName(root), obj_name);
			base->setReady(ready);
		}
	}
}

void FirstClass::printResults()
{
	std::cout << "Test result" << std::endl;
	show();
}