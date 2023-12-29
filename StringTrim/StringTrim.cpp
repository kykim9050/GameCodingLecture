// StringTrim.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int StringCount(char* _Ptr)
{
    int Count = 0;
    while (_Ptr[Count])
    {
        ++Count;
    }
    return Count;
}

void LeftMoveString(char* _Ptr, int _Start)
{
    // 배열을 할당했지만 아무것도 넣어주지 않은 상태는 예외처리
    if (nullptr == _Ptr)
    {
        return;
    }

    // stringcount를 사용하는게 좋아 보입니다.
    int StrLen = StringCount(_Ptr);

    // idx가 0일 때
    if (0 >= _Start)
    {
        for (int i = 1; i < StrLen; i++)
        {
            // 앞으로 한칸씩 밀어주기
            _Ptr[i - 1] = _Ptr[i];
        }
    }
    else
    {
        for (int i = _Start; i < StrLen; i++)
        {
            char CurCh = _Ptr[i];

            // 앞으로 한칸씩 밀어주기
            _Ptr[i - 1] = _Ptr[i];
        }
    }
    // 배열의 마지막 idx를 0으로
    _Ptr[StrLen - 1] = 0;
}

void DeleteChar(char* _Ptr, char _DeleteCh)
{
    int StrLen = StringCount(_Ptr);

    // 데이터 순회
    for (int i = 0; i < StrLen; i++)
    {
        char CurCh = _Ptr[i];
        
        // 특정 문자가 나올때마다 호출
        if (_DeleteCh == CurCh)
        {
            // LeftMoveString 함수 실행    
            LeftMoveString(_Ptr, i+1);

            // StrLen 값을 하나 빼주어야 함
            --StrLen;
        }
    }
}

int main()
{
    {
        //               01234
        char Arr[100] = "abcde";
        LeftMoveString(Arr, 3);
        // "abcde";
    }

    {
        char Arr[100] = "a b c d e";
        DeleteChar(Arr, 'b');
        // Arr = abcde
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
