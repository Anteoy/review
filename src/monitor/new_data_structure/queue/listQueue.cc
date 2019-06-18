#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX_SIZE 50
using namespace std;

typedef int ElemType;

typedef struct {
    ElemType data[MAX_SIZE];
    int front,rear;
} ListQueue;


void initQueue(ListQueue &listQueue){
    listQueue.front = listQueue.rear = 0;
}

int isEmpty(ListQueue listQueue){
    return listQueue.front == listQueue.rear;
}

int EnQueue(ListQueue &listQueue, ElemType x){
    if ((listQueue.rear + 1)%MAX_SIZE == listQueue.front) {//队满
        return 0;
    }
    listQueue.rear = (listQueue.rear + 1) % MAX_SIZE;
    listQueue.data[listQueue.rear] = x;
    return 1;
}

int DeQueue(ListQueue &listQueue, ElemType &x){
    listQueue.front = (listQueue.front+1)%MAX_SIZE;
    x = listQueue.data[listQueue.front];
    return 1;
}

void print(ListQueue listQueue){
    while ( (listQueue.rear + 1)%MAX_SIZE != ++listQueue.front%MAX_SIZE && listQueue.front%MAX_SIZE < MAX_SIZE) {
//        listQueue.front++;
        cout << listQueue.data[listQueue.front] << " ";
    }
    cout << endl;
}

int main(){
    //方式1 Enqueue等都需要解除引用用* 且堆上内存需要free
    ListQueue* listQueue = (ListQueue*)malloc(sizeof(ListQueue));
    //方式2 栈上分配内存不需要free 且Enqueue直接传值或者引用
//    ListQueue listQueue;
    initQueue(*listQueue);
    int empty = isEmpty(*listQueue);
    cout << "is empty res: " << empty << endl;
    EnQueue(*listQueue,1);
    EnQueue(*listQueue,2);
    EnQueue(*listQueue,3);
    EnQueue(*listQueue,4);
    EnQueue(*listQueue,5);
    EnQueue(*listQueue,6);
    EnQueue(*listQueue,7);
    print(*listQueue);
    ElemType e;
    DeQueue(*listQueue,e);
    cout << "dequeue e : " << e << endl;
    print(*listQueue);
    free(listQueue);
}