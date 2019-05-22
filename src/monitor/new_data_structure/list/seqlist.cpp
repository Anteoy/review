//
// Created by zhoudazhuang on 19-5-22.
//

#include <iostream>
#include "seqlist.h"
using namespace std;

typedef int ElemType;

typedef struct {
    ElemType data[MAX_SIZE];
    //单独的length，而非底层数组的length
    int length;
} SqList;

void InitList(SqList &L) {
    L.length = 0;
}

int get(SqList L,int i, ElemType &e){
    if (i <0 || i >= L.length) {
        return 0;
    }
    e = L.data[i];
    return 1;
}

int find(SqList L, ElemType e){
    for (int i = 0;i<L.length;i++) {
        if (L.data[i] == e){
            return i;
        }
    }
    return 0;
}

int insert(SqList &L, ElemType e, int i){
    //允许在末尾端插入
    if (i <0 || i >= L.length + 1) {
        return 0;
    }
    //移位
    L.length++;
    for (int j=L.length - 1;j>i;j--) {
        L.data[j] = L.data[j-1];
    }
    L.data[i] = e;
    return 1;
}

int deleteE(SqList &L, int i, ElemType &e){
    if (i <0 || i >= L.length) {
        return 0;
    }
    e = L.data[i];
    for (int j = i; j < L.length - 1; j++) {
        L.data[j] = L.data[j+1];
    }
    L.length--;
    return 1;
}

int printList(SqList sqList);

int main(){
    SqList sqList;
    InitList(sqList);
    insert(sqList,21,0);
    insert(sqList,1,1);
    insert(sqList,2,2);
    insert(sqList,3,3);
    insert(sqList,4,4);
    insert(sqList,5,5);
    insert(sqList,6,6);
    insert(sqList,7,7);
    insert(sqList,8,8);
    insert(sqList,9,0);
    insert(sqList,10,7);
    printList(sqList);
    ElemType elemTypeGet = 0;
    cout << "获得:" << elemTypeGet << endl;
    get(sqList,1,elemTypeGet);
    cout << "获得:" << elemTypeGet << endl;
    elemTypeGet = 2;
    int index = find(sqList,elemTypeGet);
    cout << "index: " << index << endl;
    ElemType deletedElement  = 0;
    deleteE(sqList,1,deletedElement);
    cout << "删除: " << deletedElement << endl;
    printList(sqList);
}

int printList(SqList sqList){
    for (int i = 0; i < sqList.length; i++) {
        cout << sqList.data[i] << " ";
    }
    cout << endl;
}