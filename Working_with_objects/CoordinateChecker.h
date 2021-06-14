#ifndef COORDINATECHECKER_H
#define COORDINATECHECKER_H
#include "BaseClass.h"
#include <sstream>
#include <fstream>
#include <cctype>

/*Successor class, inherits base class*/
class CoordinateChecker : public BaseClass
{
public:
	using BaseClass::BaseClass; //Using members of base class 
	/**
	* Returns true if coordinates of inserting symbol are correct, false otherwise
	*
	* @param x - X coordinate
	* @param y - Y coordinate
	* @return true if coordinates of inserting symbol are correct, false otherwise
	*/
	bool checkCoordinates(int x, int y);

	/**
	* Formats string with message that contains coordinates and symbol to insert
	*
	* @param message - reference to string that will store formatted message
	*/
	void Signal(std::string& message);

	/**
	* Checks coordinates of inserting symbol if coordinates are coorect, method emits signal else method prints error message to end of the file. This method uses base class method to send signals
	*
	* @param x - X coordinate
	* @param y - Y coordinate
	* @param symbol - symbol to insert
	*/
	void emitSignal(int x, int y, char symbol);

	/**
	* Returns pointer to signal method converted to type of pointer to base class method
	*
	* @return Ópointer to signal method converted to type of pointer to base class method
	*/
	static TYPE_SIGNAL getSignal();
};

#endif