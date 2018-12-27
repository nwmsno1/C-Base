#include <stdio.h>
#include <stdlib.h>

void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
        for (size_t i=0; i<arraySize; i++)
        {
                array[i]=getNextValue();
        }
}

int getNextRandomValue(void)
{
        return rand();
}

int main(void)
{
        int myarray[10];
        populate_array(myarray, 10, getNextRandomValue);
        for (int i=0; i<10; i++)
        {
                printf("%d\n", myarray[i]);
        }
        return 0;
}

/*size_t 是一种数据类型，近似于无符号整型，但容量范围一般大于 int 和 unsigned。这里使用 size_t 
是为了保证 arraysize 变量能够有足够大的容量来储存可能大的数组。*/
