#include <iostream>
#include <stdlib.h>
using namespace std;


template <typename T>
void display(T a)
{
    cout << a << endl;
}

template <typename T,class C>
void display(T t,C c)
{
    cout << t << endl;
    cout << c << endl;
}

template <typename T,int a>
void display(T t)
{
    for (int i = 0;i<a;i++) 
    {
        cout << a << endl;
    }
}

int main(void)
{
    cout << "aaa" << endl;
    display<int>(10);
    display<double>(10.58);
    display<int,double>(11,11.22);
    display<int,3>(6);
    return 0;
}