/**
 *=============================================================================
 * @Description : Solution for XXX problem from leetcode.
 * @Author      : phillee (email: phillee2016@163.com)
 * @Date        : 2021-07-06
 * @LICENSE     : Copyright (c) philleer 2021. All Rights Reserved.
 *=============================================================================
 */
/**
 * Include header files
 */
#include <stdio.h>   // stdin/stdout/stderr
#include <unistd.h>  // STDIN_FILENO/STDOUT_FILENO/STDERR_FILENO/usleep/stdin
#include <string.h>  // strlen

/**
 * Declaration for functions and global variables
 */
typedef struct 
{
	/**
	 * 字符数组和字符串，最根本的区别是在内存中的存储区域不一样。
	 * 字符数组存储在全局数据区或栈区，第二种形式的字符串存储在常量区。
	 * 全局数据区和栈区的字符串（也包括其他数据）有读取和写入的权限，而常量区的字符串（也包括其他数据）只有读取权限，没有写入权限。
	 * 关于全局数据区、栈区、常量区以及其他的内存分区，我们在《C语言和内存》专题中有详细讲解，帮助你从根本上理解C语言。
	 * 内存权限的不同导致的一个明显结果就是，字符数组在定义后可以读取和修改每个字符，而对于第二种形式的字符串，一旦被定义后就只能读取不能修改，任何对它的赋值都是错误的。
	 */
	// For more difference between string and str-array, please refer to http://c.biancheng.net/cpp/html/80.html
	char str[200];
	char result[200];
	void (*p_function)(const char *src_str, char *dst_str);
} Solution;

void str_reverse(const char* src_str, char *dst_str);

/**
 * Main function entrance
 */
int main(const int argc, char * argv[])
{
	Solution solver;
	solver.p_function = str_reverse;

    /* core module */
	printf("Please input string to be reversed: ");
	/**
	 * ANSIC 标准向 scanf() 增加了一种新特性，称为扫描集(scanset)。
	 * 扫描集定义一个字符集合，可由 scanf() 读入其中允许的字符并赋给对应字符数组。
	 * 扫描集合由一对方括号中的一串字符定义，左方括号前必须缀以百分号。
	 */
	// Get string with blank space!
	// 读入’\n’ 以外的其他字符，并在字符串末尾加’\0’，包括换行符。
	scanf("%[^\n]", solver.str);
	(*(solver.p_function))(solver.str, solver.result);
	printf("The result: %s\n", solver.result);

	return 0;
}

/**
 * Definition of the declared functions
 */
void str_reverse(const char* src_str, char *dst_str)
{
	int i = 0;
	int str_len = strlen(src_str);

	for (i=str_len-1; i>=0; --i)
	{
		*(dst_str+str_len-1-i) = src_str[i];	
	}
}
