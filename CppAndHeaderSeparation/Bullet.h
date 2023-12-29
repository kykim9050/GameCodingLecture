#pragma once
class Bullet
{
public:
	Bullet(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{
	}

	bool& GetIsFireRef()
	{
		return IsFire;
	}

	inline int2 GetPos()
	{
		return Pos;
	}

	inline char GetRenderChar()
	{
		return RenderChar;
	}

private:
	bool IsFire = false;
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};