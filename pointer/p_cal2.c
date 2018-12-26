#include <stdio.h>

const int Max=3;

int main(void)
{
        int var[]={10, 100, 1000};
        int i, *ptr;

        ptr=var;
        i=0;
        while(ptr<=&var[Max-1])
        {
                printf("address: var[%d]=%x\n", i, ptr);
                printf("value: var[%d]=%d\n", i, *ptr);

                ptr++;
                i++;
        }

        return 0;
}
