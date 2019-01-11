#include <stdio.h>

typedef struct t1
{
        char x;
        int y;
        double z;
}T1;

typedef struct t2
{
        char x;
        double z;
        int y;
}T2;

int main(int argc, char* argv[])
{
        printf("sizeof(T1) = %lu\n", sizeof(T1));
        printf("sizeof(T2) = %lu\n", sizeof(T2));

        return 0;
}


/*T1: 若从第 0 个字节开始分配内存，则 T1.x 存入第 0 字节，T1.y 占 4 个字节，由于第一的 4 字节已有数据，所以 T1.y 存入第 4-7 个字节>，T1.z 占 8 个字节，由于第一个 8 字节已有数据，所以 T1.z 存入 8-15 个字节。共占有 16 个字节。

T2: 若从第 0 个字节开始分配内存，则 T1.x 存入第 0 字节，T1.z 占 8 个字节，由于第一的 8 字节已有数据，所以 T1.z 存入第 8-15 个字节，
T1.y 占 4 个字节，由于前四个 4 字节已有数据，所以 T1.z 存入 16-19 个字节。共占有 20 个字节。此时所占字节不是最宽元素（double 长度为
 8）的整数倍，因此将其补齐到 8 的整数倍，最终结果为 24。*/
