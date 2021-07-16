/**
 *=============================================================================
 * @Description : Solution for Two Sum problem from leetcode.
 * @Author      : phillee (email: phillee2016@163.com)
 * @Date        : 2021-07-06
 * @LICENSE     : Copyright (c) philleer 2021. All Rights Reserved.
 *=============================================================================
 */
/**
 * Include header files
 */
#include <stdio.h>	 // stdin/stdout/stderr
#include <termios.h> // tcgetattr/tcsetattr
#include <unistd.h>  // STDIN_FILENO/STDOUT_FILENO/STDERR_FILENO/usleep/stdin
#include <curses.h>
#include <string.h>	 // strlen

#define NB_DISABLE 0x00
#define NB_ENABLE  0x01

/**
 * Declaration for functions and global variables
 */
void nonblock(int state);
int kbhit(void);

void solution(int *nums, const int target);

/**
 * Main function entrance
 */
int main(const int argc, char * argv[])
{
	float weight;
	float value;
	printf("Please enter your weight in pounds: ");
	scanf("%f", &weight);
	value = 770 * weight * 14.5833f;
	printf("Your weight worth: $%.2f.\n", value);
	printf("%d in hex format is %#x\n", 770, 770);
	printf("%d in hex format is %#o\n", 770, 770);

    /* core module */
	int overflow_var = 2147483647;
	signed int sign_var = -10;
	unsigned int unsign_var = 100;
	printf("%d, %d, %d\n", overflow_var, overflow_var+1, overflow_var+3);
	printf("sign_var=%d, unsign_var=%d\n", sign_var, unsign_var);

	// int i=0;

	// nonblock(NB_ENABLE);
	// while(!i)
	// {
	// 	// suspend execution for microsecond intervals
	// 	usleep(5);
	// 	i=kbhit();
	// 	if (i!=0)
	// 	{
	// 		if ('q'==fgetc(stdin))
	// 			i=1;
	// 		else
	// 			i=0;
	// 	}

	// 	printf("Please input the array:\n");
	// 	int *p_int;
	// 	char tmp_str[100];

	// 	while (NULL==fgets(tmp_str, strlen(tmp_str), stdin))
	// 	{

	// 	}
	// 	printf("Input string: %s\n", tmp_str);
	// 	int length;

	// 	int nums[5] = {1,2,3,4,5};
	// 	int target = 2;
	// 	// solution(nums, target);
	// }
	// nonblock(NB_DISABLE);

	return 0;
}

/**
 * Definition of the declared functions
 */
void nonblock(int state)
{
	struct termios ttystate;

	// get the terminal state
	tcgetattr(STDIN_FILENO, &ttystate);

	if (state==NB_ENABLE) {
		// turn off canonical mode
		ttystate.c_lflag &= ~ICANON;
		// minimum of number input read.
		ttystate.c_cc[VMIN] = 1;
	} else if (state==NB_DISABLE) {
		// turn on canonical mode
		ttystate.c_lflag |= ICANON;
	}
	// set the terminal attributes.
	tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

/**
 * For more information about FD_SET/FD_ZERO/FD_ISSET, please refer to
 * 	https://linux.die.net/man/3/fd_zero
 */
int kbhit()
{
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds); // synchronous I/O multiplexing
	FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
	return FD_ISSET(STDIN_FILENO, &fds);
}

void solution(int *nums, const int target)
{
	printf("Hello world!\n");
}

/*
 //=============================================================================
 // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ stdio.h //////////////////////////////// *
 //=============================================================================
 // extern FILE *stdin;
 // extern FILE *stdout;
 // extern FILE *stderr;
 //
 //=============================================================================
 // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ termios.h //////////////////////////////// *
 //=============================================================================
 // tcsendbreak/tcdrain/tcflush/tcflow
 // cfmakeraw/cfgetispeed/cfgetospeed
 // cfsetispeed/cfsetospeed/cfsetspeed
 //
 //=============================================================================
 // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ unistd.h //////////////////////////////// *
 //=============================================================================
 // STDIN_FILENO: Standard input value, stdin. Its value is 0.
 // STDOUT_FILENO: Standard output value, stdout. Its value is 1.
 // STDERR_FILENO: Standard error value, stderr. Its value is 2.
 */
