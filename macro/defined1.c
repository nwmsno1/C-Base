#include <stdio.h>
//#define MAX 100 
// 定义一个宏定义的标识符MAX,他代表100，MAX是常量
#define square(x) ((x) * (x))

#define square_1(x) (x * x)

int main(void)
{
        printf("square 5+4 is %d\n", square(5+4));
        printf("square_1 5+4 is %d\n", square_1(5+4));
        return 0;
}
