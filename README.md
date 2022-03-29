# 공부하면서 참고한 것들 꿀팀이나 알고리즘 여기다가 다 정리해놓으려고 함

> ## 단축키들

    > ctrl + shift + v : md파일 preview 바로 열기
    
    > ctrl + shift + L : 해당 변수 전부 선택
    > ctrl + shift + D : 해당 변수 하나씩 늘려나가며 선택

    > ctrl + x   : 한줄 지우기
    > ctrl + enter

> ## 알고리즘
    악
    


> ## 답 확인할때 은근 유용함
```c++
#include <windows.h> (윈도우에서만 가능)
void textcolor(int color_number);

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}
4: 빨간색 
7: 흰색
```



