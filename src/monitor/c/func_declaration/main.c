#include <stdio.h>
#include "sum.h"

//函数声明
int main(){
    int begin = 5, end = 86;
    int result = sum(begin, end);
    printf("The sum from %d to %d is %d\n", begin, end, result);
    return 0;
}
