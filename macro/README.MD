# 宏用法
***
---
___
## 1.前言
C语言程序中广泛的使用宏定义，采用关键字define进行定义，宏只是一种简单的字符串替换，根据是否带参数分为无参和带参。
宏定义不是C/C++严格意义上的语句，所以定义后不加分号，使用define后的标示符来代替常量，当我们需要在程序中多次使用200这个值，比如定义数组的长度等，并且可能在以后对该值做出修改时，使用宏定义，我们仅需要改变宏定义所表示的值即可，而不需要到程序中去寻找哪些地方使用了200。
### （1）宏中包含特殊符号：#、##
### （2）宏定义用do{ }while(0)
## 2.特殊符号#、##
### （1）#
When you put a # before an argument in a preprocessor  macro, the preprocessor turns that argument into a character array. 
在一个宏中的参数前面使用一个#,预处理器会把这个参数转换为一个字符数组
简化理解：#是“字符串化”的意思，出现在宏定义中的#是把跟在后面的参数转换成一个字符串
   
    #define ERROR_LOG(module)   fprintf(stderr,"error: "#module"\n")
    ERROR_LOG("add"); //转换为 fprintf(stderr,"error: "add"\n");
    ERROR_LOG(devied =0); //转换为 fprintf(stderr,"error: devied=0\n");
   
（2）##
“##”是一种分隔连接方式，它的作用是先分隔，然后进行强制连接。
在普通的宏定义中，预处理器一般把空格解释成分段标志，对于每一段和前面比较，相同的就被替换。但是这样做的结果是，被替换段之间存在一些空格。
如果我们不希望出现这些空格，就可以通过添加一些##来替代空格。

    1 #define TYPE1(type,name)   type name_##type##_type
    2 #define TYPE2(type,name)   type name##_##type##_type

TYPE1(int, c); 转换为：int 　name_int_type ; (因为##号将后面分为 name_ 、type 、 _type三组，替换后强制连接)
TYPE2(int, d);转换为： int 　d_int_type ; (因为##号将后面分为 name、_、type 、_type四组，替换后强制连接)

## 3、宏定义中do{ }while(0)
采用这种方式是为了防范在使用宏过程中出现错误，主要有如下几点：
### （1）空的宏定义避免warning:`#define foo() do{}while(0)`
### （2）存在一个独立的block，可以用来进行变量定义，进行比较复杂的实现
### （3）如果出现在判断语句过后的宏，这样可以保证作为一个整体来是实现：
```
　　　　#define foo(x) \
　　　　　　　 action1(); \
　　　　　　 　action2();
　　　　在以下情况下：
　　　　if(NULL == pPointer)
 　　　　　　  foo();
　　　　就会出现action1和action2不会同时被执行的情况，而这显然不是程序设计的目的。
```
### （4）以上的第3种情况用单独的{}也可以实现，但是为什么一定要一个do{}while(0)呢，看以下代码：
```
    #define switch(x,y) {int tmp; tmp="x";x=y;y=tmp;}
    if(x>y)
        switch(x,y);
    else       //error, parse error before else
        otheraction();
```
在把宏引入代码中，会多出一个分号，从而会报错。这对这一点，可以将if和else语句用{}括起来，可以避免分号错误。
使用do{….}while(0) 把它包裹起来，成为一个独立的语法单元，从而不会与上下文发生混淆。同时因为绝大多数的编译器都能够识别do{…}while(0)这种
无用的循环并进行优化，所以使用这种方法也不会导致程序的性能降低

## Test
```
#include <stdio.h>

#define PRINT1(a,b)        \
    {                  \
      printf("print a\n"); \
      printf("print b\n"); \
    }

#define      PRINT2(a, b)      \
  do{               \
      printf("print a\n"); \
      printf("print b\n"); \
    }while(0)  

#define PRINT(a) \
    do{\
    printf("%s: %d\n",#a,a);\
    printf("%d: %d\n",a,a);\
    }while(0)

#define TYPE1(type,name)   type name_##type##_type
#define TYPE2(type,name)   type name##_##type##_type

#define ERROR_LOG(module)   fprintf(stderr,"error: "#module"\n")

 main()
{
    int a = 20;
    int b = 19;
    TYPE1(int, c);
    ERROR_LOG("add");
    name_int_type = a;
    TYPE2(int, d);
    d_int_type = a;

    PRINT(a);
    if (a > b)
    {
    PRINT1(a, b);
    }
    else
    {
    PRINT2(a, b);
    }
    return 0;
}
```
