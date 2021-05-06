#include "FirstClass.h"
#include "SecondClass.h"
#include "ThirdClass.h"
#include "FourthClass.h"
#include "FifthClass.h"
#include "RootClass.h"

void RootClass::start()
{
	std::string root_name, parent_name, object_name;
	int class_number, ready;
	BaseClass* parent;
	BaseClass* object = nullptr;

	std::cin >> root_name;
	this->setName(root_name);
	this->setReady(1);
	std::cin >> parent_name;

	while (parent_name != "endtree")
	{
		std::cin >> object_name >> class_number >> ready;
		parent = this->getObjectFromPath(parent_name);
		if (class_number == 2)
		{
			object = new FirstClass(parent, object_name);
			object->setReady(ready);
		}
		if (class_number == 3)
		{
			object = new SecondClass(parent, object_name);
			object->setReady(ready);
		} if (class_number == 4)
		{
			object = new ThirdClass(parent, object_name);
			object->setReady(ready);
		}
		if (class_number == 5)
		{
			object = new FourthClass(parent, object_name);
			object->setReady(ready);
		}
		if (class_number == 6)
		{
			object = new FifthClass(parent, object_name);
			object->setReady(ready);
		}
		else
		{
			object = nullptr;
		}
		std::cin >> parent_name;
	}
}
void RootClass::showTree()
{
	std::cout << "Object tree" << std::endl;
	this->printTree(this, 0);
	this->findObjectFromCoordinate();
}


void RootClass::findObjectFromCoordinate()
{
	std::string address, temp_address;
	BaseClass* object;
	std::cin >> address;
	while (address != "//")
	{
		temp_address = address;
		if (temp_address[0] == '/' && temp_address[1] == '/')
		{
			temp_address.erase(temp_address.begin(),
				temp_address.begin() + 2);
			object = this->getObjectFromName(temp_address);
		}
		else
		{
			object = getObjectFromPath(address);
		}
		std::cout << std::endl;
		std::cout << address << " Object ";

		object == nullptr
			? std::cout << "not found"
			: std::cout << "name: " << object->getName();
		std::cin >> address;
	}
}