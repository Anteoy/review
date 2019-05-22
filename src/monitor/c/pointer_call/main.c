#include<stdio.h>
//值传递
 void change1(int n){
    printf("值传递--函数操作地址: %d\n", &n);
    n++;
}

//引用传递
void change2(int & n){
    printf("值传递--函数操作地址: %d\n", &n);
    n++;
}
 //指针传递
void change3(int *n){
    printf("值传递--函数操作地址: %d\n", &n);
    *n=*n+1;
    // *n++; 这样不能改变n的值
    // n++;这样也不能改变n的值
 } 
int main(){
    int n=10;
    printf("实参的地址: %d\n", &n);
    change1(n);
    printf("after change1() n= %d\n", &n);
    change2(n);
    printf("after change2() n= %d\n", &n);
    change3(&n);
    printf("after change3() n= %d\n", &n);
    return true;
}