#include <iostream>

int main()
{
    using namespace std;
    int* p = new int[3]; // new运算符返回第一个元素的地址。
    p[0] = 10;
    p[1] = 9;
    p[2] = 8;
    for (int i = 0; i < 3; i++) {
        cout << p[i] << endl;
    }

    *p = 20;
    *(p+1) = 19;
    *(p+2) = 18;
    for (int i = 0; i < 3; i++) {
        cout << p[i] << endl;
    }

    *p = 30;
    *(++p) = 29;
    *(++p) = 28;
    p-=2;  // 需要提供delete正确的地址 上面两次++了 这次梭回来-2
    for (int i = 0; i < 3; i++) {
        cout << p[i] << endl;
    }

    delete [] p;          // 释放整个数组，new如果带[] 则delete也需要带[]
    return 0;
}