#include "stdio.h"

/*

在C语言的标准库中，printf、scanf、sscanf、sprintf、sscanf这些标准库的输入输出函数，参数都是可变的。在调试程序时
，我们可能希望定义一个参数可变的输出函数来记录日志，那么用可变参数的宏是一个不错的选择。

在C99中规定宏也可以像函数一样带可变的参数，如：

#define LOG(format, ...) fprintf(stdout, format, __VA_ARGS__)  
其中，...表示可变参数列表，__VA_ARGS__在预处理中，会被实际的参数集（实参列表）所替换。
同时gcc还支持带可以变参数名的方式（注意：VC不支持）：

#define LOG(format, args...) fprintf(stdout, format, args)  
同样，args在预处理过程中，会被实际的参数集所替换。其用法和上面的方式一样，只是参数的符号有变。

需要注意的是，上述两种方式的可变参数不能省略，尽管可以传一个空参数进去。说到这里，有必要提一下“##”连接符号的用法，“##”的作用是对token进行连接
，上例中format，args，__VA_ARGS都可以看作是token，如果token为空，“##”则不进行连接，所以允许省略可变参数。对上述2个示例的改造：
#define LOG(format, ...) fprintf(stdout, format, ##__VA_ARGS__)  
#define LOG(format, args...) fprintf(stdout, format, ##args)  
即然参数可以省略，那么用宏定义一个开关，实现一个输出日志的函数就简单了：

#ifdef DEBUG  
#define LOG(format, ...) fprintf(stdout, ">>>>>" format "<<<<", ##__VA_ARGS__)  
#else  
#define LOG(format, ...)  
#endif  

*/

#define LOG_TYPE1(format, ...)      printf(format, __VA_ARGS__)
#define LOG_TYPE2(format, args...)  printf(format, args)
#define LOG_TYPE3(format, ...)      printf(">>>>>" format "<<<<\n", ##__VA_ARGS__)
#define LOG_TYPE4(format, args...)  printf(format, ##args)
#define LOG_TYPE5(...)              printf(__VA_ARGS__)
#define LOG(x) printf("LOG "#x" %d \n", x);

int value = 10;

int main()
{

	printf("hello world. \n");
	
	//LOG_TYPE1("hello %d \n");	error
	LOG_TYPE1("hello %d \n", 1);
	
	//LOG_TYPE2("hello \n"); error
	LOG_TYPE2("hello %d \n", 2);
	
	LOG_TYPE3("hello 3");
	LOG_TYPE3("hello %d", 3);
	
	LOG_TYPE4("hello 4\n");
	LOG_TYPE4("hello %d\n", 4);

    LOG_TYPE5("hello 5\n");
	LOG_TYPE5("hello %d\n", 5);
	

	LOG(10);
	LOG(value);

	return 0;
}