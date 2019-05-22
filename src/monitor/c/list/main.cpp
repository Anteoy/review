#include <stdio.h>  
#include <stdlib.h> 

//链表的链式存储
typedef struct ListNode{
    int data;
    struct ListNode * next;
} LNode, *LinkList;

//头插法 只能是.cpp 如果是.c会编译出错 因为c是没有引用的 &这里这种用法 但是比较怪啊 用gcc居然可以编译 不需要用g++ 但是 文件名的后缀只能是cpp 而不是能c
LinkList CreatList1(LinkList &L){
    LNode *s;
    int x;
    //头节点即头指针
    L -> next = NULL;
    scanf("%d", &x);
    while(x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        printf("插入: %d\n",x);
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//尾插法
LinkList CreatList2(LinkList &L){
    int x;
   LinkList L1 = (LinkList)malloc(sizeof(LNode));
   L = L1;
    LNode *s,*r = L; // r为表尾指针 指向表尾
    //头节点即头指针
    L -> next = NULL;
    scanf("%d", &x);
    while(x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;//更新表尾节点
        scanf("%d", &x);
    }
    r->next = NULL; //因为最后一个元素的next没有设置 猜测可能不安全
    return L;
}



int main(){
    LinkList L = (LinkList)malloc(sizeof(LinkList));
    CreatList2(L);
    while (L){
        printf(" %d",L->data);
        L = L->next;
    }
    free(L);
}