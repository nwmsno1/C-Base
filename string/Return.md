# Windows、Unix、Mac不同操作系统的换行问题 回车符\r和换行符\n

## 一、概念：
**换行符‘\n’和回车符‘\r’**

（1）换行符就是另起一行  --- '\n' 10 换行（newline）

（2）回车符就是回到一行的开头 --- '\r' 13 回车（return）

所以我们平时编写文件的回车符应该确切来说叫做**回车换行符**  

**CR: 回车(Carriage Return) \rLF: 换行(Line Feed) \n**

## 二、应用：
（1）在微软的MS-DOS和Windows中，使用“回车CR('\r')”和“换行LF('\n')”两个字符作为换行符;

（2）Windows系统里面，每行结尾是 回车+换行(CR+LF)，即“\r\n”；

（3）Unix系统里，每行结尾只有 换行LF，即“\n”；

（4）Mac系统里，每行结尾是 回车CR 即'\r'。

Mac OS 9 以及之前的系统的换行符是 CR，从 Mac OS X （后来改名为“OS X”）开始的换行符是 LF即‘\n'，和Unix/Linux统一了。

## 三、影响：
（1）一个直接后果是，Unix/Mac系统下的文件在Windows里打开的话，所有文字会变成一行；

（2）而Windows里的文件在Unix/Mac下打开的话，在每行的结尾可能会多出一个^M符号。

（3）Linux保存的文件在windows上用记事本看的话会出现黑点。

## 四、可以相互转换：
在linux下，命令unix2dos 是把linux文件格式转换成windows文件格式，命令dos2unix 是把windows格式转换成linux文件格式。

在不同平台间使用FTP软件传送文件时, 在ascii文本模式传输模式下, 一些FTP客户端程序会自动对换行格式进行转换. 经过这种传输的文件字节数可能会发生变化.

 如果你不想ftp修改原文件, 可以使用bin模式(二进制模式)传输文本。

一个程序在windows上运行就生成CR/LF换行格式的文本文件，而在Linux上运行就生成LF格式换行的文本文件。
