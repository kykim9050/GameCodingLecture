// StringContains.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

enum class StringReturn
{
    ERROR = -1,
    Equal,  // 0
    NotEqual    // 1
};

StringReturn StringEqual(const char* const _Left, const char* const _Right)
{
    if (nullptr == _Left || nullptr == _Right)
    {
        printf_s("Error : 인자의 포인터 값이 nullptr이 아닌지 확인하시오\n");
        return StringReturn::ERROR;
    }

    const char* const _LeftTemp = _Left;
    const char* const _RightTemp = _Right;

    int _LeftLen = static_cast<int>(strlen(_Left));
    int _RightLen = static_cast<int>(strlen((_Right)));

    int EqualCount = 0;

    if(_LeftLen == _RightLen)
    {
        for (int i = 0; i < _LeftLen; i++)
        {
            if (_Left[i] == _Right[i])
            {
                ++EqualCount;
            }
            else
            {
                break;
            }
        }

        if (_LeftLen == EqualCount)
        {
            return StringReturn::Equal;
        }
    }

    return StringReturn::NotEqual;
}

void StringAdd(char* _Dest, const char* const _Left, const char* const _Right)
{
    if (nullptr == _Dest || nullptr == _Left || nullptr == _Right)
    {
        printf_s("Error : 인자의 포인터 값이 nullptr이 아닌지 확인하시오\n");
        return;
    }

    //char* _DestTemp = _Dest;
    const char* const _LeftTemp = _Left;
    const char* const _RightTemp = _Right;

    int _LeftLen = static_cast<int>(strlen(_Left));
    int _RightLen = static_cast<int>(strlen((_Right)));

    int CopyIdx = 0;
    
    // _Left 를 _Dest앞에 복붙
    for (CopyIdx; CopyIdx < _LeftLen; ++CopyIdx)
    {
        _Dest[CopyIdx] = _LeftTemp[CopyIdx];
    }

    for (CopyIdx; CopyIdx < _LeftLen + _RightLen; CopyIdx++)
    {
        _Dest[CopyIdx] = _RightTemp[CopyIdx - _LeftLen];
    }
    return;
}

//int StringContains(const char* const _Dest, const char* const _Find)
//{
//    return;
//}

int main()
{
    {
        // 오른쪽과 왼쪽이 같아?
        int result = static_cast<int>(StringEqual("abc", "abcd"));
        int a = 0;
    }

    {
        char Arr[100] = {};
        StringAdd(Arr, "da", "cdafgg");
        // "cccccddddd"
        int a = 0;
    }

    //{
    //    // int Result = StringContains("ababcccccabab", "ab");

    //    int Result = StringContains("ababcccccabab", "c");

    //    int a = 0;
    //}
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
