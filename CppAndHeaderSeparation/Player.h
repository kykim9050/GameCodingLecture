// 헤더에는 아래의 #pragma once를 꼭 넣어야 합니다.
#pragma once
#include "Math.h"

// 헤더에는 선언만 놓습니다.
class Player
{
public:
	//함수들이 구현까지 다 되어있는 상황이다.
	// 구현을 다 삭제하고
	Player();
	Player(char _RenderChar);

	// 굉장히 간단한 함수.
	// 선언과 구현을 분리하면 inline이 되지 않는다.
	// 보통 굉장히 간단한 함수는 선언과 구현을 분리하지 않아요.
	// 보통 Get과 Set함수 혹은 Get만 하는 사람도 있다.
	inline char GetRenderChar()
	{
		return RenderChar;
	}

	void Update();
	void SetBulletFire(bool* _IsFire);

private:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
	bool* IsFire = nullptr;
};

