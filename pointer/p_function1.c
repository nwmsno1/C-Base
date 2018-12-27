#include <stdio.h>

int max(int x, int y)
{
        return x>y ? x:y;
}

int main(void)
{
        /* p 是函数指针 */
        // typedef int (*fun_ptr)(int,int);声明一个指向同样参数、返回值的函数指针类型
        int (*p)(int, int) = &max; // &可以省略
        int a, b, c, d;

        printf("please input 3 numbers:");
        scanf("%d %d %d", &a, &b, &c);
        /* 与直接调用函数等价，d = max(max(a, b), c) */
        d = p((a, b), c);

        printf("the max number is: %d\n", d);
        return 0;
}
  
