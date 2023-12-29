#include <iostream>

class A
{
public:
	int Value = 0;
	
	B newB;

};

class B
{
public:
	int Value2 = 0;

	A NewA;
};


int main()
{
	A test;
}