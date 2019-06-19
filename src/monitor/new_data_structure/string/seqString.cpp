#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MaxSize 50
using namespace std;

typedef struct {
    char data[MaxSize];
    int length;
} SqString;

//void StrAssign(SqString & str, char* cstr){
void StrAssign(SqString & str, char cstr[ ], int len){
    int i;

    //char cs[4] = {'a','b','c','d'}; 这种不会自动加\0
//    for (i=0; cstr[i] != '\0' && cstr[i] != '\377' && cstr[i] != '\177';i++) {
    for (i=0; i < len;i++) {
        str.data[i] = cstr[i];
        printf("%d ",str.length);
        printf("%c ", str.data[i]);
//        str.length = str.length + 1;
// or
        str.length++;
    }
    printf("\n");
}

void StrCopy(SqString& s, SqString t){
    int i;
    for (i=0;i<t.length;i++){
        s.data[i] = t.data[i];
    }
    s.length = t.length;
}

int StrLength(SqString& s){
    return s.length;
}

SqString Concat(SqString s, SqString t){
    //栈上分配 =声明+初始化
    SqString str;
    int i;
    str.length = s.length + t.length;
    for (i=0;i<s.length;i++) {
        str.data[i] = s.data[i];
    }
    for (i=0;i<t.length;i++){
        str.data[s.length + i] = t.data[i];
    }
    return str;
}

void DispStr(SqString s){
    int i;
    if (s.length > 0) {
        for (i = 0;i<s.length;i++) {
            cout << s.data[i] << endl;
            //or
//            printf("%c",s.data[i]);
//            printf("\n");
        }
    }
}

int main(){
    char cs[4] = {'a','b'}; //不足4 则会补\0
//用这个在main中不是数组 不能用下面的sizeof 会计算为8
//    char* cs = "abcd";
    char* cs1 = {"abcd"};
    //上面的不会加\0 只有这种会
    char cs3[] = {"abcd"};
    char cs2[3] = {'e','f','g'};
    SqString string1;
    SqString string2;
    int lencs = sizeof(cs)/ sizeof(cs[0]);
    int lencs2 = sizeof(cs2)/ sizeof(cs2[0]);
    StrAssign(string1,cs,lencs);
    StrAssign(string2,cs2, lencs2);
    DispStr(string1);
    cout << "-----" << endl;
    DispStr(string2);
    cout << "-----" << endl;
    SqString sqString = Concat(string1,string2);
    DispStr(sqString);
}