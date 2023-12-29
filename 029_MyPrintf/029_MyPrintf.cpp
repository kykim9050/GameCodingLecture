// 029_MyPrintf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


void NumberToString(int _Number, char* _Ptr)
{
	// 어떤 함수든 원본값을 보존해 놓는게 좋음
	int CalNumber = _Number;
	int NumberCount = 0;
	const char* CPtr = _Ptr;

	while (CalNumber)
	{
		CalNumber /= 10;
		++NumberCount;
	}

	int Mul = 1;

	for (int i = 0; i < NumberCount - 1; i++)
	{
		Mul *= 10;
	}

	int Value = 0;
	CalNumber = _Number;

	// 숫자를 분해하기 시작함
	for (int i = 0; i < NumberCount; i++)
	{
		// 0 나누기는 허용되지 않는다
		// 문자로 바꾸기 위해서는 '0'을 더해준다.
		Value = CalNumber / Mul;
		_Ptr[i] = Value + '0';
		CalNumber -= Value * Mul;
		Mul /= 10;
	}
}

int MyPrintf(const char* const _Format, ...)
{
	// 500번지는 정수형 주소이니까 64비트 정수형으로 형 변환해서 써야 함
	__int64 Address = reinterpret_cast<__int64>(&_Format);
	// C스타일 자체가 원하는 형태로 바꿔서 쓰라는 것 (기본적으로)
	// printf는 C에서 만들었기에
	// 내부에 수정을 막기 위해서 const를 앞에 붙여줌 (원래는 수정되면 안되기 때문)
	Address = Address + 8;

	int Count = 0;
	while (_Format[Count])
	{
		// 값 받아보기 필수
		char Ch = _Format[Count];


		// 포맷팅이 아닐 경우 글자를 출력하고 다시 반복한다.
		if ('%' != Ch)
		{
			// 로직이 깔끔하게 끝나는걸 선호
			putchar(_Format[Count]);
			++Count;
			continue;
		}

		// 포매팅 문자인 %를 만났을 경우
		char NextCh = _Format[Count + 1];

		// 상태가 명확할 경우 switch 사용
		// 상황에 맞게 조건문을 사용하는 것
		switch (NextCh)
		{
		case 'd':
		{
			int* Ptr = reinterpret_cast<int*>(Address);
			// 인자를 끌어내야 함

			char Arr[100] = {};

			NumberToString(*Ptr, Arr);

			int Index = 0;
			while (Arr[Index])
			{
				putchar(Arr[Index]);
				++Index;
				++Count;
			}
			break;
		}
		default:
			break;
		}
	}

	return Count;
}


int main()
{
	{
		int Return = MyPrintf("aaa bbb ccc %d", 123);
		int a = 0;
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
