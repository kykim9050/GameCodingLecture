#pragma once
class ProbUnit
{
public:
	void ProbReset(int _DivideVal);

	inline int GetProb() const
	{
		return Prob;
	}

private:
	int Prob = 0;
};

