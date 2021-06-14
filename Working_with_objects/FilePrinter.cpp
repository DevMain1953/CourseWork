#include "FilePrinter.h"

std::string FilePrinter::readTextFile(std::string file_name)
{
	std::string text, temp_text;
	std::ifstream file(file_name);
	while (getline(file, temp_text))
	{
		text += temp_text + '\n';
	}
	file.close();
	return text;
}

void FilePrinter::printFileContent(std::string file_name)
{
	std::string result = readTextFile(file_name);
	std::cout << result.erase(result.length() - 1, std::string::npos); //Removes new line symbol
}