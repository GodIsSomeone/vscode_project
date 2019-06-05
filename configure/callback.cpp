#include <stdlib.h>
#include <stdio.h>
#include "master.h"

// 外部函数
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i = 0; i < arraySize; i++)
    {
        array[i] = getNextValue();
        if(i==2)
            array[i] += 3;
    }
}


// 获取随机值
int getNextRandomValue(void)
{
    return 3;
}

int main(void)
{
    int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
