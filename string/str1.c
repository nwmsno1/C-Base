#include <stdio.h>

int main()
{
	//char greeting[6]={'H', 'e', 'l', 'l', 'o', '\0'};
	char greeting[]="Hello";

	printf("Greeting message: %s\n", greeting);

	return 0;
}

//在 C 语言中，字符串实际上是使用 null 字符 '\0' 终止的一维字符数组
