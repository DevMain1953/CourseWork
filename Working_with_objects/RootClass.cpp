#include "FirstClass.h"
#include "SecondClass.h"
#include "ThirdClass.h"
#include "FourthClass.h"
#include "FifthClass.h"
#include "RootClass.h"

RootClass::~RootClass()
{
	for (int i = 0; i < connects.size(); i++)
	{
		delete connects[i];
	}
}

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
		parent = this->getObjectFromName(parent_name);
		if (class_number == 2)
		{
			object = new FirstClass(parent, object_name);
			object->setReady(ready);
		}
		if (class_number == 3)
		{
			object = new SecondClass(parent, object_name);
			object->setReady(ready);
		}
		if (class_number == 4)
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

void RootClass::app()
{
	std::cout << "Object tree" << std::endl;
	this->Connections();
	this->printTree(this, 0);
	this->printConnects();
	this->emitSignal();
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

void RootClass::Connections()
{
	int connection_number;
	std::string object, object1;
	BaseClass* base_object;
	std::cin >> connection_number;
	while (connection_number != 0)
	{
		std::cin >> object >> object1;
		base_object = getObjectFromName(object);
		base_object->setConnection(RootClass::getSignal(base_object -> getNumber()), getObjectFromName(object1), RootClass::getHandler(getObjectFromName(object1)->getNumber()));
		connection_struct* a = new connection_struct;
		a->object = object;
		a->number = connection_number;
		a->object1 = object1;
		connects.push_back(a);
		std::cin >> connection_number;
	}
}

void RootClass::printConnects()
{
	std::cout << "\nSet connects";
	for (int i = 0; i < connects.size(); i++)
	{
		std::cout << "\n" << connects[i]->number << " " << connects[i] -> object << " " << connects[i]->object1;
	}
}

void RootClass::emitSignal()
{
	BaseClass* object;
	std::string name, text;
	std::cout << "\nEmit signals";
	std::cin >> name;
	while (name != "endsignals")
	{
		std::cin >> text;
		object = getObjectFromName(name);
		object->sendSignal(RootClass::getSignal(object->getNumber()), text);
		std::cin >> name;
	}
}

void RootClass::Signal(std::string& text)
{
	text = " Text: " + this->getName() + " -> " + text;
}

void RootClass::Handler(std::string text)
{
	std::cout << "\nSignal to " << this->getName() << text;
}

TYPE_SIGNAL RootClass::getSignal(int number)
{
	if (number == 1)
	{
		return SIGNAL_MACRO(RootClass, Signal);
	}
	if (number == 2)
	{
		return SIGNAL_MACRO(FirstClass, Signal);
	}
	if (number == 3)
	{
		return SIGNAL_MACRO(SecondClass, Signal);
	}
}

TYPE_HANDLER RootClass::getHandler(int number)
{
	if (number == 1)
	{
		return HANDLER_MACRO(RootClass, Handler);
	}
	if (number == 2)
	{
		return HANDLER_MACRO(FirstClass, Handler);
	}
	if (number == 3)
	{
		return HANDLER_MACRO(SecondClass, Handler);
	}
}