#include <stdio.h>

const int MAX = 4;

int main ()
{
   const char *names[] = {
                   "Zara Ali",
                   "Hina Ali",
                   "Nuha Ali",
                   "Sara Ali",
   };
   int i = 0;

   for ( i = 0; i < MAX; i++)
   {
      printf("Value of names[%d] = %s\n", i, names[i] );
   }
   return 0;
}

/*指针数组

指针数组：指针数组可以说成是”指针的数组”，首先这个变量是一个数组。

其次，”指针”修饰这个数组，意思是说这个数组的所有元素都是指针类型。

在 32 位系统中，指针占四个字节。

数组指针

数组指针：数组指针可以说成是”数组的指针”，首先这个变量是一个指针。

其次，”数组”修饰这个指针，意思是说这个指针存放着一个数组的首地址，或者说这个指
针指向一个数组的首地址。

根
据上面的解释，可以了解到指针数组和数组指针的区别，因为二者根本就是种类型的变量
。*/       
