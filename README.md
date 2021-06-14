# CourseWork
This repository contains course work project. The main task is to learn how developer can work with different objects in hierarchical tree. This readme file contains API documentation (generated by Doxygen) and class diagram see below.

## Class diagram
![Class diagram](https://github.com/Pirate1953/CourseWork/blob/master/images/class_diagram.png)

# Task 3.1 - 3.2 API docs
## In BaseClass class
### [BaseClass::BaseClass(BaseClass* parent)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L3)
### Description
Creates object in the hierarchy, if parent object exists, creates subordinate object.
### Parameters
1. parent	- pointer to parent object 
### Return
No

### [BaseClass::BaseClass(BaseClass* parent, std::string name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L13)
### Description
Creates object in the hierarchy, if parent object exists, creates subordinate object and sets name to it.
### Parameters
1. parent	- pointer to parent object 
2. name	- object name 
### Return
No

### [BaseClass::~BaseClass()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L23)
### Description
Removes subordinate objects and connections
### Parameters
No
### Return
No

### [void BaseClass::printTree(BaseClass* parent, int space)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L90)
### Description
Prints hierarchical tree.
### Parameters
1. parent	- pointer to parent object 
2. space	- number of spaces in hierarchical tree before branch 
### Note
This method uses recursive call through pointer in array of subordinate objects.
### Return
No

### [BaseClass* BaseClass::getObjectFromName(std::string name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L69)
### Description
Returns pointer to object in hierarchical tree.
### Parameters
1. name	- object name to find
### Note
This method uses recursive call through pointer in array of subordinate objects.
### Return
Pointer to object in hierarchical tree 

### [std::string BaseClass::getName()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L45)
### Description
Returns object name.
### Parameters
No
### Return
Object name  

### [void BaseClass::setName(std::string name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L40)
### Description
Sets name to the object.
### Parameters
1. name	- object name
### Return
No

### [void BaseClass::setReady(int ready)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L35)
### Description
Sets ready state to the object.
### Parameters
1. ready	- ready state
### Return
No

### [void BaseClass::show()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L50)
### Description
Prints objects and their ready state.
### Parameters
No
### Note
This method uses recursive call through pointer in array of subordinate objects.
### Return
No

## In FirstClass class
### [void FirstClass::printResults()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/FirstClass.cpp#L39)
### Description
Prints result, calls 'show' method.
### Parameters
No
### Return
No

### [void FirstClass::start()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/FirstClass.cpp#L6)
### Description
Starts algorithm of setting data and hierarchical tree construction.
### Parameters
No
### Return
No

## In RootClass class
### [void RootClass::showTree()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L65)
New method name is 'app' (in Task 3.4)

### [void RootClass::start()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L16)
### Description
Starts algorithm of setting data from keyboard for hierarchical tree construction.
### Parameters
No
### Note
Algorithm is almost same as in previous task, all 5 classes was used.
### Return
No

# Task 3.3 API Docs
## In RootClass class
### [void RootClass::findObjectFromCoordinate()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L74)
### Description
Finds objects in hierarchical tree using their coordinates then prints search result (object found or not found)
### Parameters
No
### Return
No

## In BaseClass class
### [void BaseClass::getChildFromName(std::string name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L100)
### Description
Returns pointer to subordinate object.
### Parameters
1. name - subordinate object name to find
### Return
Pointer to subordinate object

### [void BaseClass::getObjectFromPath(std::string path)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L112)
### Description
Returns pointer to object using its location in hierarchical tree.
### Parameters
1. path - path to the object
### Return
Pointer to object

# Task 3.4 API Docs
## In BaseClass class
### [void BaseClass::setConnection(TYPE_SIGNAL signal, BaseClass* object, TYPE_HANDLER handler)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L143)
### Description
Sets connection between objects
### Parameters
1. signal - pointer to signal method
2. object - pointer to target object
3. handler - pointer to handler method
### Note
Adds new element (pointer to structure that describes connections) to array of pointers
### Return
No

### [void BaseClass::removeConnection(TYPE_SIGNAL signal, BaseClass* object, TYPE_HANDLER handler)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L160)
### Description
Removes connection
### Parameters
1. signal - pointer to signal method
2. object - pointer to target object
3. handler - pointer to handler method
### Note
Removes pointer to structure that describes connections from array
### Return
No

### [void BaseClass::sendSignal(TYPE_SIGNAL signal, std::string& command)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L173)
### Description
Sends signal
### Parameters
1. signal - pointer to signal method
2. command - reference to string that contains a message
### Return
No

### [int BaseClass::getNumber()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L187)
### Description
Returns class number
### Parameters
No
### Return
Class number

## In FirstClass class
### [void FirstClass::Signal(std::string& text)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/FirstClass.cpp#L45)
### Description
Builds a message text
### Parameters
1. text - reference to string to build message
### Return
No

### [void FirstClass::Handler(std::string text)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/FirstClass.cpp#L50)
### Description
Prints a message
### Parameters
1. text - a message to print
### Return
No

## In SecondClass class
### [void SecondClass::Signal(std::string& text)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/SecondClass.cpp#L3)
### Description
Builds a message text
### Parameters
1. text - reference to string to build message
### Return
No

### [void SecondClass::Handler(std::string text)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/SecondClass.cpp#L8)
### Description
Prints a message
### Parameters
1. text - a message to print
### Return
No

## In RootClass class
### RootClass(BaseClass* parent)
### Description
Initializes constructor of BaseClass with one parameter
### Parameters
1. parent - pointer to parent object
### Return
No

### [RootClass::~RootClass()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L8)
### Description
Removes array of pointers to structure with connection number, and object names
### Parameters
No
### Return
No

### [void RootClass::app()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L65)
### Description
Calls method to print hierarchical object tree and methods to print and emit signal
### Parameters
No
### Note
This method prints "Object tree" before calling method to print hierarchical object tree
### Return
No

### [void RootClass::Connections()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L102)
### Description
Sets connections between objects
### Parameters
No
### Note
This method uses methods to get pointers to signal and handler methods
### Return
No

### [void RootClass::printConnects()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L122)
### Description
Prints connections from array of connections
### Parameters
No
### Return
No

### [void RootClass::emitSignal()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L131)
### Description
Emits signal, uses BaseClass method to send signal
### Parameters
No
### Return
No

### [void RootClass::Signal(std::string& text)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L146)
### Description
Builds a message text
### Parameters
1. text - reference to string to build message
### Return
No

### [void RootClass::Handler(std::string text)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L151)
### Description
Prints a message
### Parameters
1. text - message to print
### Return
No

### [TYPE_SIGNAL RootClass::getSignal(int number)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L156)
### Description
Returns pointer to signal method that is casted to pointer to BaseClass method
### Parameters
1. number - class number
### Return
Pointer to signal method that is casted to pointer to BaseClass method

### [TYPE_HANDLER RootClass::getHandler(int number)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/RootClass.cpp#L172)
### Description
Returns pointer to handler method that is casted to pointer to BaseClass method
### Parameters
1. number - class number
### Return
Pointer to handler method that is casted to pointer to BaseClass method

# Task K_1 API docs
## In TextFile class
### [TextFile(BaseClass* parent)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/TextFile.h#L19)
### Description
Initializes constructor of base class with one parameter
### Parameters
1. parent	- pointer to parent object 
### Return
No

### [void TextFile::start()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/TextFile.cpp#L6)
### Description
Builds hierarchical object tree and sets connection between 'sender' object and 'target' object
### Parameters
No
### Return
No

### [void TextFile::app()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/TextFile.cpp#L23)
### Description
Starts algorithm to input coordinates and symbol and insert it to text file, at the end method calls method to print content of text file
### Parameters
No
### Return
No

### [void TextFile::createTextFile(std::string file_name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/TextFile.cpp#L46)
### Description
Creates new text file and sets name for it, writes numeric 10x10 matrix of number 8 to file
### Parameters
1. file_name - name of file
### Return
No

### [void TextFile::Connection()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/TextFile.cpp#L61)
### Description
Sets connection between two objects
### Parameters
No
### Note
This method uses methods to get pointers to signal and handler methods
### Return
No

## In CoordinateChecker class
### [bool CoordinateChecker::checkCoordinates(int x, int y)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/CoordinateChecker.cpp#L3)
### Description
Returns true if coordinates of inserting symbol are correct, false otherwise
### Parameters
1. x - X coordinate
2. y - Y coordinate
### Return
True if coordinates of inserting symbol are correct, false otherwise

### [void CoordinateChecker::Signal(std::string& message)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/CoordinateChecker.cpp#L8)
### Description
Formats string with message that contains coordinates and symbol to insert
### Parameters
1. message - reference to string that will store formatted message
### Return
No

### [void CoordinateChecker::emitSignal(int x, int y, char symbol)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/CoordinateChecker.cpp#L13)
### Description
Checks coordinates of inserting symbol if coordinates are coorect, method emits signal else method prints error message to end of the file. This method uses base class method to send signals
### Parameters
1. x - X coordinate
2. y - Y coordinate
3. symbol - symbol to insert
### Return
No

### [TYPE_SIGNAL CoordinateChecker::getSignal()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/CoordinateChecker.cpp#L35)
### Description
Returns pointer to signal method converted to type of pointer to base class method
### Parameters
No
### Return
Pointer to signal method converted to type of pointer to base class method

## In MatrixInserter class
### [bool MatrixInserter::isLatin(char symbol)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/MatrixInserter.cpp#L3)
### Description
Returns true if symbol is from latin alphabet, false otherwise
### Parameters
1. symbol - symbol to check
### Return
True if symbol is from latin alphabet, false otherwise

### [TYPE_HANDLER MatrixInserter::getHandler()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/MatrixInserter.cpp#L8)
### Description
Returns pointer to handler method converted to type of pointer to base class method
### Parameters
No
### Return
Pointer to handler method converted to type of pointer to base class method

### [std::string MatrixInserter::readMatrixFromTextFile(std::string file_name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/MatrixInserter.cpp#L13)
### Description
Returns string from text file that contains matrix 10x10
### Parameters
1. file_name - name of file to open
### Return
String from text file that contains matrix 10x10

### [void MatrixInserter::Handler(std::string message)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/MatrixInserter.cpp#L25)
### Description
Performs inserting new symbol to text file, if message contains symbol that is not from latin alphabet, method inserts error message to the end of file
### Parameters
1. message - message that contains new symbol and position of inserting
### Return
No

### [std::string MatrixInserter::readTextFile(std::string file_name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/MatrixInserter.cpp#L79)
### Description
Returns string that contains all data from text file
### Parameters
1. file_name - name of file to open
### Return
String that contains all data from text file

## In FilePrinter class
### [std::string FilePrinter::readTextFile(std::string file_name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/FilePrinter.cpp#L3)
### Description
Returns string that contains all data from text file
### Parameters
1. file_name - name of file to open
### Return
String that contains all data from text file

### [void FilePrinter::printFileContent(std::string file_name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/FilePrinter.cpp#L15)
### Description
Prints content from text file to output stream
### Parameters
1. file_name - name of file to open and read
### Return
No
