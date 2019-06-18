#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;


double f(float A[], int i){
    if (i==0) {
        return A[0];
    }
    double m = f(A, i-1);
    if (m > A[i]) {
        return A[i];
    } else {
        return m;
    }
}

double f2(float* A, int i){
    if (i==0) {
        return A[i];
    }
    double m = f(A, i-1);
    if (m > A[i]) {
        return A[i];
    } else {
        return m;
    }
}

int main(){
    float A[7] = {1,6,4,8,9,23,-1};
    double m = f(A,6);
    cout << "最小值为: " << m << endl;
//    float *B = new float[7];
    // or
    float *B = malloc(7*sizeof(int))
    for (int i=0;i<7;i++) {
        *(B+i) = i+10;
    }
    for (int i = 0; i < 7; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
//    double mb = f(B,6);//两种方式都可以
    double mb = f2(B,6);
    cout << "最小值为: " << mb << endl;
//    delete [] B;
// or
    free(B);
}