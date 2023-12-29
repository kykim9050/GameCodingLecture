// String.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 글자수를 세서 리턴하는 함수
int StringCount(const char* _Ptr)
{
    // count 초기화
    int Count = 0;

    // 글자 수 하나하나 인덱스로 접근해서 count 증가
    while (_Ptr[Count])
    {
        // _Ptr[Count] = 'b';
        Count += 1;
    }
    
    // 최종 길이를 반환
    return Count;

}

// StringCount를 사용할 수 있다
void StringReverse(char* _Ptr)
{
    // 어디까지 바꿔야 하는지 알아야 하기 때문에 길이를 받아온다
    int StrLen = StringCount(_Ptr);
    int count = StrLen / 2;

    // 길이의 반만큼 반복문을 수행하면서
    // 스왑 알고리즘 을 적용한다.
    for (int i = 0; i < count; ++i)
    {
        char TempCh = _Ptr[i];
        _Ptr[i] = _Ptr[StrLen -1 -i];
        _Ptr[StrLen - 1 - i] = TempCh;
    }
}



int main()
{
    // 배열의 크기, 데이터를 언제든지 바꿀 수 있다는 것을 염두
    // 함수가 하는 일에 포커싱을 맞출 것
    // 공백은 넣지 않음answk
    // 영어만 취급
    // 끝이 0인 것은 오류로 볼 것
    {
        char Arr[10] = "dddfadddd";
        int Result = StringCount(Arr);
        int a = 0;
    }

    {
        char Arr[10] = "ABCEF";
        StringReverse(Arr);
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
