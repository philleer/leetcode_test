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
#include <math.h>

/**
 * Declaration for functions and global variables
 */
int my_add(int num1, int num2);

/**
 * Main function entrance
 */
int main(const int argc, char * argv[])
{
    /* core module */
	int num1 = 0;
	int num2 = 0;
	printf("Please input the two numbers:\n");
	scanf("%d,%d", &num1, &num2);
	printf("The addition of the given num is: %d\n", my_add(num1, num2));

	return 0;
}

/**
 * Definition of the declared functions
 */
int my_add(int num1, int num2) {
	return (num1+num2);
}
