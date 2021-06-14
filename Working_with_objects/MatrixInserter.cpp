#include "MatrixInserter.h"

bool MatrixInserter::isLatin(char symbol)
{
	return std::isalpha(static_cast<int>(symbol));
}

TYPE_HANDLER MatrixInserter::getHandler()
{
	return HANDLER_MACRO(MatrixInserter, Handler);
}

std::string MatrixInserter::readMatrixFromTextFile(std::string file_name)
{
	std::string text, temp_text;
	std::ifstream file(file_name);
	while (getline(file, temp_text))
	{
		text += temp_text;
	}
	file.close();
	return text.substr(0, 100);
}

void MatrixInserter::Handler(std::string message)
{
	std::vector<std::string> arguments;
	std::string str;
	std::stringstream stream(message);

	/*Receiving data from message*/
	while (getline(stream, str, ' '))
	{
		arguments.push_back(str);
	}
	stream.str("");

	/*Converting data*/
	int new_x = std::stoi(arguments[0]);
	int new_y = std::stoi(arguments[1]);
	char new_symbol = (arguments[2])[0];

	/*Inserting data to matrix and inserting matrix to file*/
	if (isLatin(new_symbol))
	{
		std::string error_messages = readTextFile("field.txt").substr(110, std::string::npos);
		std::string text_matrix = readMatrixFromTextFile("field.txt");
		char matrix[10][10];
		int counter = 0;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				matrix[i][j] = text_matrix[counter++];
			}
		}
		matrix[new_x - 1][new_y - 1] = new_symbol;
		std::ofstream file("field.txt", std::ios::out);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				file << matrix[i][j];
			}
			file << '\n';
		}
		file << error_messages; //Writing unchangeable data to file
		file.close();
	}
	else
	{
		std::ofstream file("field.txt", std::ios::app);
		file << "Not a letter of the Latin alphabet: " << new_symbol << "\n";
		file.close();
	}
}

std::string MatrixInserter::readTextFile(std::string file_name)
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
