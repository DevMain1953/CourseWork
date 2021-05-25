#include "SecondClass.h"

void SecondClass::Signal(std::string& text)
{
	text = " Text: " + this->getName() + " -> " + text;
}

void SecondClass::Handler(std::string text)
{
	std::cout << "\nSignal to " << this->getName() << text;
}