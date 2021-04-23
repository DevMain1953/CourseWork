# CourseWork
This repository contains course work project. This readme file contains API documentation and class diagram see below.

## Class diagram
![Class diagram](https://github.com/Pirate1953/CourseWork/blob/master/images/class_diagram.png)

## API docs
In BaseClass class
### [BaseClass::BaseClass(BaseClass* parent)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L3)
### Description
Creates root object in the hierarchy, if such object already exists, creates subordinate object.
### Parameters
1. parent	- pointer to parent object 
### Return
No

### [BaseClass::BaseClass(BaseClass* parent, std::string name)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L13)
### Description
Creates root object in the hierarchy, if such object already exists, creates subordinate object and sets name to it.
### Parameters
1. parent	- pointer to parent object 
2. name	- object name 
### Return
No

### [BaseClass::~BaseClass()](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L23)
### Description
Removes subordinate objects.
### Parameters
No
### Return
No

### [void BaseClass::ConstructTree(BaseClass* parent, int space)](https://github.com/Pirate1953/CourseWork/blob/master/Working_with_objects/BaseClass.cpp#L86)
### Description
Constructs and prints hierarchical tree.
### Parameters
1. parent	- pointer to parent object 
2. space	- number of spaces in hierarchical tree before branch 
### Note
This method uses recursive call through pointer in array of subordinate objects.
### Return
No
