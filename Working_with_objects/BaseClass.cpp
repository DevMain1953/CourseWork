#include "BaseClass.h"

BaseClass::BaseClass(BaseClass* parent)
{
	if (parent != 0)
	{
		parent->children.push_back(this);
	}
	this->parent = parent;
	ready = 1;
}

BaseClass::BaseClass(BaseClass* parent, std::string name)
{
	this->parent = parent;
	if (parent != 0)
	{
		parent->children.push_back(this);
	}
	this->name = name;
}

BaseClass::~BaseClass()
{
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void BaseClass::setReady(int ready)
{
	this->ready = ready;
}

void BaseClass::setName(std::string name)
{
	this->name = name;
}

std::string BaseClass::getName()
{
	return this->name;
}

void BaseClass::show()
{
	std::cout << "The object " << getName().c_str();
	if (ready > 0)
	{
		std::cout << " is ready";
	}
	else
	{
		std::cout << " is not ready";
	}

	for (int i = 0; i < children.size(); i++)
	{
		std::cout << std::endl;
		children[i]->show();
	}
}

BaseClass* BaseClass::find(std::string name)
{
	BaseClass* temp = NULL;
	if (name == this->getName().c_str())
	{
		temp = this;
	}
	else if (children.size() > 0)
	{
		for (int i = 0; i < children.size(); i++)
		{
			temp = children[i]->find(name);
			if (temp != NULL)
			{
				break;
			}
		}
	}
	return temp;
}

void BaseClass::ConstructTree(BaseClass* parent, int space)
{
	for (int i = 0; i < space; i++)
	{
		std::cout << " ";
	}
	std::cout << parent->getName();
	for (int i = 0; i < parent->children.size(); i++)
	{
		std::cout << std::endl;
		children[i]->ConstructTree(this->children[i], space + 4);
	}
}
