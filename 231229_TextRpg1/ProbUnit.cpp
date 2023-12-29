#include "ProbUnit.h"
#include <iostream>

void ProbUnit::ProbReset(const int _DivideVal)
{
	int CalProb = rand() % _DivideVal;

	Prob = CalProb;
}