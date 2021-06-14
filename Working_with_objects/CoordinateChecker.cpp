#include "CoordinateChecker.h"

bool CoordinateChecker::checkCoordinates(int x, int y)
{
	return ((x > 0 && x < 11) && (y > 0 && y < 11));
}

void CoordinateChecker::Signal(std::string& message)
{
	message.erase(message.length() - 1, std::string::npos);
}

void CoordinateChecker::emitSignal(int x, int y, char symbol)
{
	if (checkCoordinates(x, y))
	{
		BaseClass* base_object;
		std::string message_text;
		std::stringstream stream;
		stream << x << " " << y << " " << symbol << '\n';
		message_text = stream.str();
		stream.str(""); //Clears content in stream

		base_object = getObjectFromName("sender");
		base_object->sendSignal(CoordinateChecker::getSignal(), message_text);
	}
	else
	{
		std::ofstream file("field.txt", std::ios::app);
		file << "Coordinate is wrong ( " << x << ", " << y << " )\n";
		file.close();
	}
}

TYPE_SIGNAL CoordinateChecker::getSignal()
{
	return SIGNAL_MACRO(CoordinateChecker, Signal);
}