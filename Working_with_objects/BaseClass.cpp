#include "BaseClass.h"

BaseClass::BaseClass(BaseClass* parent)
{
	if (parent != nullptr)
	{
		parent->children.push_back(this);
	}
	this->parent = parent;
	ready = 1;
}

BaseClass::BaseClass(BaseClass* parent, std::string name)
{
	this->parent = parent;
	if (parent != nullptr)
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

BaseClass* BaseClass::getObjectFromName(std::string name)
{
	BaseClass* temp = nullptr;
	if (name == this->getName().c_str())
	{
		temp = this;
	}
	else if (children.size() > 0)
	{
		for (int i = 0; i < children.size(); i++)
		{
			temp = children[i]->getObjectFromName(name);
			if (temp != nullptr)
			{
				break;
			}
		}
	}
	return temp;
}

void BaseClass::printTree(BaseClass* parent, int space)
{
	for (int i = 0; i < space; i++)
	{
		std::cout << " ";
	}
	std::cout << parent->getName();
	for (int i = 0; i < parent->children.size(); i++)
	{
		std::cout << std::endl;
		children[i]->printTree(this->children[i], space + 4);
	}
}

BaseClass* BaseClass::getChildFromName(std::string name)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i]->getName() == name)
		{
			return children[i];
		}
	}
	return nullptr;
}
BaseClass* BaseClass::getObjectFromPath(std::string path)
{
	path += '/';
	std::string object_name = "";
	BaseClass* object = this;
	for (int i = 1; i < path.size(); i++)
	{
		if (path[i] == '/')
		{
			if (object_name != this->getName())
			{
				object = object->getChildFromName(object_name);
				if (object == nullptr)
				{
					break;
				}
			}
			object_name = "";
		}
		else
		{
			object_name += path[i];
		}
	}
	return object;
}