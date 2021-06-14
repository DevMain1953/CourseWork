#include "CoordinateChecker.h"
#include "MatrixInserter.h"
#include "FilePrinter.h"
#include "TextFile.h"

void TextFile::start()
{
	BaseClass* sender_object = nullptr;
	BaseClass* target_object = nullptr;
	BaseClass* print_object = nullptr;

	this->setName("root");
	this->setReady(1);
	sender_object = new CoordinateChecker(this, "sender");
	sender_object->setReady(1);
	target_object = new MatrixInserter(this, "target");
	target_object->setReady(1);
	print_object = new FilePrinter(this, "print");
	print_object->setReady(1);
	this->Connection();
}

void TextFile::app()
{
	int x, y;
	char symbol;

	createTextFile("field.txt");
	std::cin >> x >> y >> symbol;
	while (true)
	{
		static_cast<CoordinateChecker*>(getObjectFromName("sender"))->emitSignal(x, y, symbol);
		std::cin >> x >> y;
		if (x != 0 && y != 0)
		{
			std::cin >> symbol;
		}
		else
		{
			break;
		}
	}
	static_cast<FilePrinter*>(getObjectFromName("print"))->printFileContent("field.txt");
}

void TextFile::createTextFile(std::string file_name)
{
	std::ofstream file(file_name);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			file << "8";
		}
		file << '\n';
	}
	file.close();
}

/*Methods to work with signal-handler mechanism*/
void TextFile::Connection()
{
	BaseClass* base_object;
	base_object = getObjectFromName("sender");
	base_object->setConnection(CoordinateChecker::getSignal(), getObjectFromName("target"), MatrixInserter::getHandler());
}