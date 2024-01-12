#include <iostream>
#include <ConsoleEngine/EngineDebug.h>
#include <list>

typedef int MyList;

class MyList
{

};


int main()
{
	LeakCheck;


	// std list
	std::cout << "std list" << std::endl;
	std::list<int> NewList = std::list<int>();
	for (int i = 0; i < 10; i++)
	{
		NewList.push_back(i);
	}

	std::list<int>::iterator StartIter = NewList.begin();
	std::list<int>::iterator EndIter = NewList.end();

	for ( ; StartIter != EndIter; StartIter++)
	{
		std::cout << *StartIter << std::endl;
	}


	// MyList
	std::cout << "std list" << std::endl;
	MyList NewList = MyList();
	for (int i = 0; i < 10; i++)
	{
		NewList.push_back(i);
	}

	MyList::iterator StartIter = NewList.begin();
	MyList::iterator EndIter = NewList.end();

	for (; StartIter != EndIter; StartIter++)
	{
		std::cout << *StartIter << std::endl;
	}



	int a = 0;

}