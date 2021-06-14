#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>
#include <vector>
#include <string>

//Declaring aliases for pointers to BaseClass methods
class BaseClass;
typedef void (BaseClass::* TYPE_SIGNAL)(std::string&);
typedef void (BaseClass::* TYPE_HANDLER)(std::string);

/*Base class describes hierarchical object tree*/
class BaseClass
{
protected:
	std::string name; //Object name
	int number = 1; //Class number
	BaseClass* parent; //Pointer to parent object
	int ready; //Object ready state
	std::vector<BaseClass*> children; //Vector (array) of subordinate objects
	struct connection_struct //Describes connection
	{
		TYPE_SIGNAL signal;
		BaseClass* object;
		TYPE_HANDLER handler;
	};
	std::vector<connection_struct*> connects; //Vector (array) of pointers to structure


public:
	/**
	*	Creates object in the hierarchy, if parent object exists, creates subordinate object
	*
	*	@param parent - pointer to parent object
	*/
	BaseClass(BaseClass* parent);

	/**
	*	Creates object in the hierarchy, if parent object exists, creates subordinate object and sets name to it
	*
	*	@param parent - pointer to parent object
	*	@param name - object name
	*/
	BaseClass(BaseClass* parent, std::string name);

	/**
	*	Removes subordinate objects and connections
	*/
	~BaseClass();

	/**
	*	Sets ready state to the object
	*
	*	@param ready - ready state
	*/
	void setReady(int ready);

	/**
	*	Returns object name
	*
	*	@return object name
	*/
	std::string getName();

	/**
	*	Sets name to the object
	*
	*	@param name - object name
	*/
	void setName(std::string name);

	/**
	*	Returns pointer to object in hierarchical tree
	*
	*	@param name - object name to find
	*	@note This method uses recursive call through pointer in array of subordinate objects
	*
	*	@return pointer to object in hierarchical tree
	*/
	BaseClass* getObjectFromName(std::string name);

	/**
	*	Prints objects and their ready state
	*
	*	@note This method uses recursive call through pointer in array of subordinate objects
	*/
	void show();

	/**
	*	Prints hierarchical tree
	*
	*	@param parent - pointer to parent object
	*	@param space - number of spaces in hierarchical tree before branch
	*	@note This method uses recursive call through pointer in array of subordinate objects
	*/
	void printTree(BaseClass* parent, int space);

	/**
	*	Returns pointer to subordinate object
	*
	*	@param name - subordinate object name to find
	*	@return pointer to subordinate object
	*/
	BaseClass* getChildFromName(std::string name);

	/**
	*	Returns pointer to object using its location in hierarchical tree
	*
	*	@param path - path to the object
	*	@return pointer to object
	*/
	BaseClass* getObjectFromPath(std::string path);

	/**
	*	Sets connection between objects
	*
	*	@param signal - pointer to signal method
	*	@param object - pointer to target object
	*	@param handler - pointer to handler method
	*
	*	@note Adds new element (pointer to structure that describes connections) to array of pointers
	*/
	void setConnection(TYPE_SIGNAL signal, BaseClass* object, TYPE_HANDLER handler);

	/**
	*	Removes connection
	*
	*	@param signal - pointer to signal method
	*	@param object - pointer to target object
	*	@param handler - pointer to handler method
	*
	*	@note Removes pointer to structure that describes connections from array
	*/
	void removeConnection(TYPE_SIGNAL signal, BaseClass* object, TYPE_HANDLER handler);

	/**
	*	Sends signal
	*
	*	@param signal - pointer to signal method
	*	@param command - reference to string that contains a message
	*/
	void sendSignal(TYPE_SIGNAL signal, std::string& command);

	/**
	*	Returns class number
	*
	*	@return class number
	*/
	int getNumber();
};

//Declaring macros to cast pointers to signal and handler methods in sub-class.
//The result of cast is pointer to signal and handler methods in BaseClass
#define SIGNAL_MACRO(S, signal_func) (static_cast<TYPE_SIGNAL>(&S::signal_func))
#define HANDLER_MACRO(H, handler_func) (static_cast<TYPE_HANDLER>(&H::handler_func))

#endif
