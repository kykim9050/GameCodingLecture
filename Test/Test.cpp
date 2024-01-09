#include <iostream>



int main()
{
	int* num1 = new int();
	int* num2 = new int();
	int* num3 = new int();

	__int64 Address1 = reinterpret_cast<__int64>(num1);
	__int64 Address2 = reinterpret_cast<__int64>(num2);
	__int64 Address3 = reinterpret_cast<__int64>(num3);
	
	int a = 0;

	delete num1;
	delete num2;
	delete num3;
}