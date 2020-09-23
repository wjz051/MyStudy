C语言学习笔记

printf函数和putchar函数：
printf是输出一个字符串，putchar输出一个char。
printf格式字符：
打印格式	对应数据类型	含义
%d	int	接受整数值并将它表示为有符号的十进制整数
%hd	short int	短整数
%hu	unsigned short 	无符号短整数
%o	unsigned int	无符号8进制整数
%u	unsigned int	无符号10进制整数
%x,%X	unsigned int	无符号16进制整数，x对应的是abcdef，X对应的是ABCDEF
%f	float	单精度浮点数
%lf	double	双精度浮点数
%e,%E	double	科学计数法表示的数，此处"e"的大小写代表在输出时用的"e"的大小写
%c	char	字符型。可以把输入的数字按照ASCII码相应转换为对应的字符
%s	char * 	字符串。输出字符串中的字符直至字符串中的空字符（字符串以'\0‘结尾，这个'\0'即空字符）
%p	void *	以16进制形式输出指针
%%	%	输出一个百分号

printf附加格式：
字符	含义
l(字母l)	附加在d,u,x,o前面，表示长整数
-	左对齐
m(代表一个整数)	数据最小宽度
0(数字0)	将输出的前面补上0直到占满指定列宽为止不可以搭配使用-
m.n(代表一个整数)	m指域宽，即对应的输出项在输出设备上所占的字符数。n指精度，用于说明输出的实型数的小数位数。对数值型的来说，未指定n时，隐含的精度为n=6位。


scanf函数与getchar函数：
getchar是从标准输入设备读取一个char。
scanf通过%转义的方式可以得到用户通过标准输入设备输入的数据。


1) gets()
#include <stdio.h>
char *gets(char *s);
功能：从标准输入读入字符，并保存到s指定的内存空间，直到出现换行符或读到文件结尾为止。
参数：
	s：字符串首地址
返回值：
	成功：读入的字符串
	失败：NULL

gets(str)与scanf(“%s”,str)的区别：
gets(str)允许输入的字符串含有空格
scanf(“%s”,str)不允许含有空格

注意：由于scanf()和gets()无法知道字符串s大小，必须遇到换行符或读到文件结尾为止才接收输入，因此容易导致字符数组越界(缓冲区溢出)的情况。
	char str[100];
	printf("请输入str: ");
	gets(str);
	printf("str = %s\n", str);

2) fgets()
#include <stdio.h>
char *fgets(char *s, int size, FILE *stream);
功能：从stream指定的文件内读入字符，保存到s所指定的内存空间，直到出现换行字符、读到文件结尾或是已读了size - 1个字符为止，最后会自动加上字符 '\0' 作为字符串结束。
参数：
	s：字符串
	size：指定最大读取字符串的长度（size - 1）
	stream：文件指针，如果读键盘输入的字符串，固定写为stdin
返回值：
	成功：成功读取的字符串
	读到文件尾或出错： NULL

fgets()在读取一个用户通过键盘输入的字符串的时候，同时把用户输入的回车也做为字符串的一部分。通过scanf和gets输入一个字符串的时候，不包含结尾的“\n”，但通过fgets结尾多了“\n”。fgets()函数是安全的，不存在缓冲区溢出的问题。

	char str[100];
	printf("请输入str: ");
	fgets(str, sizeof(str), stdin);
	printf("str = \"%s\"\n", str);

3) puts()
#include <stdio.h>
int puts(const char *s);
功能：标准设备输出s字符串，在输出完成后自动输出一个'\n'。
参数：
	s：字符串首地址
返回值：
	成功：非负数
	失败：-1

#include <stdio.h>

int main()
{
	printf("hello world");
	puts("hello world");

	return 0;
}

4) fputs()
#include <stdio.h>
int fputs(const char * str, FILE * stream);
功能：将str所指定的字符串写入到stream指定的文件中， 字符串结束符 '\0'  不写入文件。 
参数：
	str：字符串
	stream：文件指针，如果把字符串输出到屏幕，固定写为stdout
返回值：
	成功：0
	失败：-1

fputs()是puts()的文件操作版本，但fputs()不会自动输出一个'\n'。

	printf("hello world");
	puts("hello world");
	fputs("hello world", stdout);

5) strlen()	
#include <string.h>
size_t strlen(const char *s);
功能：计算指定指定字符串s的长度，不包含字符串结束符‘\0’
参数：
s：字符串首地址
返回值：字符串s的长度，size_t为unsigned int类型

	char str[] = "abc\0defg";
	int n = strlen(str);
	printf("n = %d\n", n);

字符串处理函数
1) strcpy()
#include <string.h>
char *strcpy(char *dest, const char *src);
功能：把src所指向的字符串复制到dest所指向的空间中，'\0'也会拷贝过去
参数：
	dest：目的字符串首地址
	src：源字符首地址
返回值：
	成功：返回dest字符串的首地址
	失败：NULL

注意：如果参数dest所指的内存空间不够大，可能会造成缓冲溢出的错误情况。

char dest[20] = "123456789";
	char src[] = "hello world";
	strcpy(dest, src);
	printf("%s\n", dest);

2) strncpy()
#include <string.h>
char *strncpy(char *dest, const char *src, size_t n);
功能：把src指向字符串的前n个字符复制到dest所指向的空间中，是否拷贝结束符看指定的长度是否包含'\0'。
参数：
	dest：目的字符串首地址
	src：源字符首地址
	n：指定需要拷贝字符串个数
返回值：
	成功：返回dest字符串的首地址
	失败：NULL

	char dest[20] ;
	char src[] = "hello world";

	strncpy(dest, src, 5);
	printf("%s\n", dest);

	dest[5] = '\0';
	printf("%s\n", dest);

3) strcat()
#include <string.h>
char *strcat(char *dest, const char *src);
功能：将src字符串连接到dest的尾部，‘\0’也会追加过去
参数：
	dest：目的字符串首地址
	src：源字符首地址
返回值：
	成功：返回dest字符串的首地址
	失败：NULL

	char str[20] = "123";
	char *src = "hello world";
	printf("%s\n", strcat(str, src));

4) strncat()
#include <string.h>
char *strncat(char *dest, const char *src, size_t n);
功能：将src字符串前n个字符连接到dest的尾部，‘\0’也会追加过去
参数：
	dest：目的字符串首地址
	src：源字符首地址
	n：指定需要追加字符串个数
返回值：
	成功：返回dest字符串的首地址
	失败：NULL

	char str[20] = "123";
	char *src = "hello world";
	printf("%s\n", strncat(str, src, 5));

5) strcmp()
#include <string.h>
int strcmp(const char *s1, const char *s2);
功能：比较 s1 和 s2 的大小，比较的是字符ASCII码大小。
参数：
	s1：字符串1首地址
	s2：字符串2首地址
返回值：
	相等：0
	大于：>0 在不同操作系统strcmp结果会不同   返回ASCII差值
	小于：<0
	

char *str1 = "hello world";
	char *str2 = "hello mike";

	if (strcmp(str1, str2) == 0)
	{
		printf("str1==str2\n");
	}
	else if (strcmp(str1, str2) > 0)
	{
		printf("str1>str2\n");
	}	
	else
	{
		printf("str1<str2\n");
	}

6) strncmp()
#include <string.h>
int strncmp(const char *s1, const char *s2, size_t n);
功能：比较 s1 和 s2 前n个字符的大小，比较的是字符ASCII码大小。
参数：
	s1：字符串1首地址
	s2：字符串2首地址
	n：指定比较字符串的数量
返回值：
	相等：0
	大于： > 0
	小于： < 0
	
char *str1 = "hello world";
	char *str2 = "hello mike";

	if (strncmp(str1, str2, 5) == 0)
	{
		printf("str1==str2\n");
	}
	else if (strcmp(str1, "hello world") > 0)
	{
		printf("str1>str2\n");
	}
	else
	{
		printf("str1<str2\n");
	}

7) sprintf()
#include <stdio.h>
int sprintf(char *str, const char *format, ...);
功能：根据参数format字符串来转换并格式化数据，然后将结果输出到str指定的空间中，直到出现字符串结束符 '\0'  为止。
参数：
	str：字符串首地址
	format：字符串格式，用法和printf()一样
返回值：
	成功：实际格式化的字符个数
	失败： - 1

	char dst[100] = { 0 };
	int a = 10;
	char src[] = "hello world";
	printf("a = %d, src = %s", a, src);
	printf("\n");

	int len = sprintf(dst, "a = %d, src = %s", a, src);
	printf("dst = \" %s\"\n", dst);
	printf("len = %d\n", len);

8) sscanf()
#include <stdio.h>
int sscanf(const char *str, const char *format, ...);
功能：从str指定的字符串读取数据，并根据参数format字符串来转换并格式化数据。
参数：
	str：指定的字符串首地址
	format：字符串格式，用法和scanf()一样
返回值：
	成功：参数数目，成功转换的值的个数
	失败： - 1

	char src[] = "a=10, b=20";
	int a;
	int b;
	sscanf(src, "a=%d,  b=%d", &a, &b);
	printf("a:%d, b:%d\n", a, b);

9) strchr()
#include <string.h>
char *strchr(const char *s, int c);
功能：在字符串s中查找字母c出现的位置
参数：
	s：字符串首地址
	c：匹配字母(字符)
返回值：
	成功：返回第一次出现的c地址
	失败：NULL

	char src[] = "ddda123abcd";
	char *p = strchr(src, 'a');
	printf("p = %s\n", p);

10) strstr()
#include <string.h>
char *strstr(const char *haystack, const char *needle);
功能：在字符串haystack中查找字符串needle出现的位置
参数：
	haystack：源字符串首地址
	needle：匹配字符串首地址
返回值：
	成功：返回第一次出现的needle地址
	失败：NULL

	char src[] = "ddddabcd123abcd333abcd";
	char *p = strstr(src, "abcd");
	printf("p = %s\n", p);

11) strtok()
#include <string.h>
char *strtok(char *str, const char *delim);
功能：来将字符串分割成一个个片段。当strtok()在参数s的字符串中发现参数delim中包含的分割字符时, 则会将该字符改为\0 字符，当连续出现多个时只替换第一个为\0。
参数：
	str：指向欲分割的字符串
	delim：为分割字符串中包含的所有字符
返回值：
	成功：分割后字符串首地址
	失败：NULL

在第一次调用时：strtok()必需给予参数s字符串
往后的调用则将参数s设置成NULL，每次调用成功则返回指向被分割出片段的指针

	char a[100] = "adc*fvcv.ebcy*hghbdfg$casdert";
	char *s = strtok(a, ".*$");//将"*"分割的子串取出
	while (s != NULL)
	{
		printf("%s\n", s);
		s = strtok(NULL, "*");
	}

12) atoi()
#include <stdlib.h>
int atoi(const char *nptr);
功能：atoi()会扫描nptr字符串，跳过前面的空格字符，直到遇到数字或正负号才开始做转换，而遇到非数字或字符串结束符('\0')才结束转换，并将结果返回返回值。
参数：
	nptr：待转换的字符串
返回值：成功转换后整数

类似的函数有：
atof()：把一个小数形式的字符串转化为一个浮点数。
atol()：将一个字符串转化为long类型

	char str1[] = "          -10";
	int num1 = atoi(str1);
	printf("num1 = %d\n", num1);

	char str2[] = "0.123";
	double num2 = atof(str2);
	printf("num2 = %lf\n", num2);

	char str3[] = "123L";
	long num3 = atol(str3);
	printf("num3 = %ld\n", num3);
