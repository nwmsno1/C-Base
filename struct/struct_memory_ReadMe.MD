# C语言结构体的存储分配

## 简介
若结构体里面包含多种数据类型，其如何在内存中分配存储空间呢？
编译器在处理结构体空间分配时，采取的是对齐方式，按照结构体中成员中成员类型字节数最大的为标准，从上往下对结构体成员进行赋值，
若当前成员的字节数小于最大成员字节数，接着为下一个连续分配内存，若下一个的内存分配后会大于最大成员字节数，则为当前成员补齐至最大成员字节数。

## 具体解析
    #include<stdio.h>
 
    typedef struct node
    {
	    char a;  //1字节
	    float b;  //4字节
	    double c;  //8字节
	    int *p;   //由编译器决定
    }pnode;
    int main(int argc, char const *argv[])
    {
	    /* code */
	    pnode n;
	    printf("字节数为：%lu\n",sizeof(n) );
	    return 0;
    }

这里的字节数计算：最大字节数为c变量，8字节，接着分配时：
a:1        sum=1<8
b:4        sum=1+4<8
c:8        sum=5+8>8,补齐3个字节后再为c分配，sum=5+(3)+8=16
d:8(指针根据最大字节数来分配)    sum=16+8=24
结果为24字节。

改变下顺序
```#include<stdio.h>
 
typedef struct node
{
	char a;  //1字节
	double b;  //8字节
	float c;  //4字节	
	int *p;   //由编译器决定
}pnode;
int main(int argc, char const *argv[])
{
	/* code */
	pnode n;
	printf("字节数为：%lu\n",sizeof(n) );
	return 0;
}
