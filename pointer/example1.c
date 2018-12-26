/*C 不支持在调用函数时返回局部变量的地址，除非定义局部变量为 static 变量。

因为局部变量是存储在内存的栈区内，当函数调用结束后，局部变量所占的内存地址便被释放了，因此当其函数执行完毕后，函数内的变量便不再拥有那个内存地址，所以不能返回其指针。

除非将其变量定义为 static 变量，static 变量的值存放在内存中的静态数据区，不会随着函数执行的结束而被清除，故能返回其地址。*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/* 要生成和返回随机数的函数 */
int * getRandom()
{
        static int r[10];
        int i;

        /* 设置种子 */
        srand((unsigned)time(NULL));
        for (1=0; i<10;i++)
        {
                r[i]=rand();
                printf("%d\n", r[i])
        }
        return r;
}

/* 要调用上面定义函数的主函数 */
int main()
{
        /* 一个指向整数的指针 */
        int *p;
        int i;

        p = getRandom();
        for(i=0;i<10;i++)
        {
                printf("*(p+[%d]: %d\n)", i, *(p+i));
        }

        return 0;
}
