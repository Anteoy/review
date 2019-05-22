#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX_SIZE 10
using namespace std;
typedef int ElemType;

typedef struct{
    ElemType data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack &stack){
    stack.top = -1;
}

int isEmpty(Stack stack){
    return stack.top == -1;
}

int push(Stack &stack, ElemType elemType){
    if (stack.top == MAX_SIZE-1) {
        return 0;
    }
    stack.top++;
    stack.data[stack.top] = elemType;
    return 1;
}

int pop(Stack &stack, ElemType &elemType){
    if (stack.top == -1) {
        return 0;
    }
    elemType = stack.data[stack.top];
    stack.top--;
    return 1;
}

int getTop(Stack stack, ElemType &elemType){
    if (stack.top == -1) {
        return 0;
    }
    elemType = stack.data[stack.top];
    return 1;
}

int print(Stack stack){
    for (int i = stack.top; i >= 0; i--) {
        cout << stack.data[i] << " ";
    }
    cout << endl;
}

int main(){
    Stack* stack = new Stack;
    initStack(*stack);
    int empty = isEmpty(*stack);
    cout << "is empty: " << empty << endl;
    push(*stack,1);
    push(*stack,2);
    push(*stack,3);
    push(*stack,4);
    push(*stack,5);
    print(*stack);
    ElemType e;
    pop(*stack, e);
    cout << "pop value: " << e << endl;
    print(*stack);
    getTop(*stack,e);
    cout << "get Top: " << e << endl;
    delete stack;
}