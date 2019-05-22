#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct linkNode {
    ElemType data;
    struct linkNode* next;
} ListStack;

//[1]    28521 segmentation fault  ./a.out 如果只传递指针进来的话 如： void initStack(ListStack *&listStack){
//指针的引用，指针它也是一个变量，*&就和普通变量的引用一样，也可以理解为指针变量的别名。如LZ的例子之中，int*& a，那么在函数里面对a的值进行改变，那么在调用函数时传入的参数的指针值也会改变   再实际点的例子，LZ的void*& fun(int*& a);调用时，有一个指针int* pointer = NULL;，然后fun(pointer)，在fun里面对a重新赋值，a = &other，那样子外面pointer的值也就变成了&other
void initStack(ListStack *&listStack){
    listStack=(ListStack *)malloc(sizeof(ListStack));
    listStack->next=NULL;
}


int isEmpty(ListStack * listStack){
    return listStack->next == NULL;
}

void push(ListStack* listStack, ElemType elemType){
    ListStack *p;
    p = (ListStack *)malloc(sizeof(ListStack));
    p->data = elemType;
    p->next=listStack->next;
    listStack->next = p;
}

int pop(ListStack *listStack, ElemType &elemType){
    if (listStack->next == NULL) {
        return 0;
    }
    ListStack * p;
    p = listStack->next;
    elemType = p->data;
    listStack -> next = p->next;
    free(p);
    return 1;
}

void print(ListStack *listStack){
    ListStack *p;
    p = listStack->next;
    while (p !=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    ListStack *listStack;
    initStack(listStack);
    int isEmptyVal = isEmpty(listStack);
    cout << "is empty : " << isEmptyVal << endl;
    push(listStack,1);
    push(listStack,2);
    push(listStack,3);
    push(listStack,4);
    push(listStack,5);
    push(listStack,6);
    print(listStack);
    ElemType  elemType;
    pop(listStack,elemType);
    cout << "pop 出 ： " << elemType << endl;
    print(listStack);
}