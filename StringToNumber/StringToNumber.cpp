// StringToNumber.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 문자열의 갯수를 출력하는 함수
int StringCount(const char* const _Ptr)
{
    int Count = 0;
    while (_Ptr[Count])
    {
        ++Count;
    }
    return Count;
}


// 문자열로 받은 것을 숫자로 넘겨주는 함수
int StringToNumber(const char* const _NumberString)
{
    // 문자열의 갯수 출력
    int count = StringCount(_NumberString);
    int MaxUnit = 1;
    int result = 0;

    for (int i = 0; i < count - 1 ; i++)
    {
        MaxUnit *= 10;
    }
    
    for (int i = 0; i < count; i++)
    {
        char Ch = _NumberString[i];
        result = MaxUnit * (Ch - '0') + result;
        
        /*10단위 나눠서 감소*/
        MaxUnit /= 10;
    }

    // 계산된 값을 반환
    return result;
}


void NumberToString(int _Number, char* _Ptr)
{
	// 어떤 함수든 원본값을 보존해 놓는게 좋음
	int CalNumber = _Number;
	int NumberCount = 0;
	const char* CPtr = _Ptr;

	while (CalNumber)
	{
		CalNumber /= 10;
		NumberCount++;
	}

	int Mul = 1;
	for (int i = 0; i < NumberCount - 1; i++)
	{
		Mul *= 10;
	}

	int Value = 0;
	CalNumber = _Number;

	// 숫자를 분해하기 시작함
	for (int i = 0; i < Value; i++)
	{
		// 0 나누기는 허용되지 않는다
		// 문자로 바꾸기 위해서는 '0'을 더해준다.
		Value = CalNumber / Mul;
		_Ptr[i] = Value + '0';
		CalNumber -= Value * Mul;
		Mul /= 10;
	}


    //// 총 자릿수를 알아야 함. 순회수
    //int CalVal = _Number;
    //int count = 0;
    //int Maxcount = 1;

    //// 숫자 자릿수 출력
    //while (_Number)
    //{
    //    _Number /= 10;
    //    ++count;
    //}

    //// 최대 자리 단위
    //for (int i = 0; i < count-1; i++)
    //{
    //    Maxcount *= 10;
    //}

    //// 자릿수마다의 숫자를 배열에 하나씩 집어넣는다 (for반복문)
    //for (int i = 0; i < count; i++)
    //{
    //    // 숫자를 하나씩 분리하는 법
    //    _Ptr[i] = CalVal / Maxcount + '0';
    //    CalVal -= Maxcount * (_Ptr[i]);
    //    Maxcount /= 10;
    //}

    //// 배열에 숫자를 다 집어 넣었으면 마지막에 0을 넣어준ek
    //_Ptr[count] = 0;
}



int main()
{
    {
        int Number = StringToNumber("100383647");
        int a = 0;
    }

    {
        // 배열은 괄호만 넣어주어도 0으로 초기화가 된다
        char Arr[100] = {};
        NumberToString(123, Arr);

        int Number = StringToNumber(Arr);

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
