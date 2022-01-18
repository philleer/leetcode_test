/**
 *=============================================================================
 * @Description : Test for problems from C Premier Plus Version 5.0
 * @Version		: 1.0
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
#include <math.h>    // fabs
#include <ctype.h>   // islower, isupper
#include <time.h>    // time, time_t, strftime, localtime, localtime_r
#include <locale.h>  // LC_TIME
#include <stdlib.h>  // atoi
#include <sys/time.h>

#define TIME_FUNIT 60.0
#define TIME_IUNIT 60
#define END_OF_FILE '#'
#define PRICE 10.00
#define TIME_SCALE 1.50
#define THRESH1 300
#define THRESH2 450
#define RATE1_PERCENT 0.15
#define RATE2_PERCENT 0.20
#define RATE3_PERCENT 0.25
#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define THRESH1_NO10 17850
#define THRESH2_NO10 23900
#define THRESH3_NO10 29750
#define THRESH4_NO10 14875

#define FIRST 3
#define SECOND (FIRST*2)
#undef FIRST
#define FIRST 2

/**
 * Declaration for functions and global variables
 */
void check_system_endian(void);
int my_add(int num1, int num2);
float cubic_float (float num);
void Temperatures(double degree_fah);
double diff_over_multiply(double num1, double num2);
void show_usage(void);
void test_workspace(void);
void test_fibonacci(int n);
void text_cnt(void);

/**
 * Main function entrance
 */
int main(const int argc, char * argv[])
{
	/* core module */
	test_workspace();
	test_fibonacci(atoi(argv[1]));

	/* Casual experiment */
	int iArray_a[5] = {1,2,3,4,5};

	int *ptr1 = &iArray_a+1;
	printf("sizeof iArray_a = %d\n", sizeof(&iArray_a));
	printf("%x, %p, %p\n", ptr1[-1], iArray_a, ptr1);

	int *ptr2 = (int *)((long int)iArray_a+1);
	printf("%p, %x\n", ptr2, *ptr2);

	int iNum_z = SECOND;
	printf("FIRST=%d,SECOND=%d,iNum_z=%d\n", FIRST, SECOND, iNum_z);
	printf("size of (void *) pointer: %d\n", sizeof(void *));

	int cStr_a[5] = {'A','B','C','D'};
	int (*p1)[5] = &cStr_a;
	int (*p2)[5] = cStr_a;
	printf("%p,%p\n", p1, p2);
	printf("%p,%p\n", p1+1, p2+1);
	int (*p3)[10] = &cStr_a;
	int (*p4)[10] = cStr_a;
	printf("%p,%p\n", p3+1, p4+1);

	int iNums_a[5][5];
	int (*pNums_a)[4];
	pNums_a = iNums_a;
	printf("a_ptr=%#p,p_ptr=%#p\n", &iNums_a[4][2], &pNums_a[4][2]);
	printf("%p,%d\n", &pNums_a[4][2]-&iNums_a[4][2], &pNums_a[4][2]-&iNums_a[4][2]);

	/* Chapter 7 Programming practice No.1 */
	//char c_input;
	//int cnt_newlines = 0;
	//int cnt_chars = 0;
	//int cnt_spaces = 0;
	//while ((c_input=getchar())!=END_OF_FILE)
	//{
	//	if (isspace(c_input) && c_input!='\n')
	//	{
	//		++cnt_spaces;
	//	}
	//	else if ('\n' == c_input)
	//	{
	//		++cnt_newlines;
	//	} else
	//		++cnt_chars;	
	//}
	//printf("There are %4d chars, %4d lines and %4d space in the input text.\n", cnt_chars, cnt_newlines, cnt_spaces);

	/* Chapter 7 Programming practice No.2 */
	//char c_input;
	//int cnt_chars = 0;
	//printf("Please enter the text to be checked:\n");
	//while ((c_input=getchar())!=END_OF_FILE)
	//{
	//	printf("%c%4d ", c_input, c_input);
	//	if (0==(++cnt_chars % 8))
	//		printf("\n");
	//}
	//printf("Done!\n");

	/* Chapter 7 Programming practice No.3 */
	//int i_var = 0;
	//int cnt_odds = 0;
	//int cnt_even = 0;
	//int avg_odds = 0;
	//int avg_even = 0;
	//while (1==scanf("%d", &i_var) && i_var!=0)
	//{
	//	if (0==i_var%2)
	//	{
	//		++cnt_even;
	//		avg_even += i_var;
	//	}
	//	else
	//	{
	//		++cnt_odds;
	//		avg_odds += i_var;
	//	}
	//}
	//printf("There are %d odd num and the average of the odds is %d\nThere are %d even num and the average of the even is %d\n", cnt_odds, (int)((double)avg_odds/cnt_odds), cnt_even, avg_even/cnt_even);
	//printf("Done!\n");

	/* Chapter 7 Programming practice No.4 */
	//char c_var;
	//char c_prevar;
	//int cnt_subs = 0;
	//printf("Please enter the text to be processed:\n");
	//c_prevar = getchar();
	//while ((c_var=getchar()) && c_var!=END_OF_FILE)
	//{
	//	/* Chapter 7 Programming practice No.6 */
	//	if (c_prevar=='e' && c_var=='i')
	//		++cnt_subs;
	//	c_prevar = c_var;
	//	//if (c_var == '.')
	//	//{
	//	//	++cnt_subs;
	//	//	c_var = '!';
	//	//}
	//	//else if (c_var == '!')
	//	//{
	//	//	++cnt_subs;
	//	//	c_var = '!';
	//	//	printf("%c", c_var);
	//	//}
	//	//printf("%c", c_var);
	//}
	//printf("\n%d substitute in total!\n", cnt_subs);
	//printf("Done!\n");

	///* Chapter 7 Programming practice No.7 && No.8 */
	//int i_var = 0;
	//int index = 0;
	//float f_price = 0.f;
	//show_usage();
	//while (1==scanf("%d", &index))
	//{
	//	switch(index)
	//	{
	//		case 1: f_price = PAY_RATE1; break;
	//		case 2: f_price = PAY_RATE2; break;
	//		case 3: f_price = PAY_RATE3; break;
	//		case 4: f_price = PAY_RATE4; break;
	//		case 5:
	//		default: break;
	//	}
	//	printf("Please enter the working hours:\n");
	//	scanf("%d", &i_var);
	//	float salary = PRICE*i_var;
	//	float tax = 0.f;
	//	if (i_var > 40)
	//		salary = PRICE*(40+TIME_SCALE*(i_var-40));
	//
	//	if (salary < THRESH1)
	//	{
	//		tax = salary*RATE1_PERCENT;
	//	}
	//	else if (salary < THRESH2)
	//	{
	//	tax = THRESH1*RATE1_PERCENT + (salary-THRESH1)*RATE2_PERCENT;
	//	}
	//	else
	//	{
	//		tax = THRESH1*RATE1_PERCENT + (THRESH2-THRESH1)*RATE2_PERCENT + (salary-THRESH2)*RATE2_PERCENT;
	//	}
	//	printf("The working time is accumulated to %d hours, the salary is $%.2f, the tax is $%.2f, and the final income is $%.2f\n", i_var, salary, tax, salary-tax);
	//	show_usage();
	//}

	/* Chapter 7 Programming practice No.9 */
	//int i_var = 0;
	//printf("Please enter an integer:\n");
	//scanf("%d", &i_var);
	//printf("All prime num less than the input is shown as below:\n");
	//for (int iter=2; iter<i_var; ++iter)
	//{
	//	char prime_flag = 1;
	//	for (int i=2; i*i<=iter; ++i)
	//	{
	//		if (0==iter%i)
	//		{
	//			prime_flag = 0;
	//			break;
	//		}
	//	}
	//	if (prime_flag)
	//		printf("%d\n", iter);
	//}

	/* Chapter 7 Programming practice No.10 */
	//int stereotype = 0;
	//double salary = 0.f;
	//double part1 = 0.f;
	//double part2 = 0.f;
	//printf("Please enter the type and salary:\n");
	//while (2==scanf("%d %lf", &stereotype, &salary))
	//{
	//	switch(stereotype)
	//	{
	//		case 1: {
	//				if (salary < THRESH1_NO10)
	//				{
	//					part1 = salary;
	//					part2 = 0.f;
	//				}
	//				else
	//				{
	//					part1 = THRESH1_NO10;
	//					part2 = salary-THRESH1_NO10;
	//				}
	//			}
	//			break;
	//		case 2: {
	//				if (salary < THRESH2_NO10)
	//				{
	//					part1 = salary;
	//					part2 = 0.f;
	//				}
	//				else
	//				{
	//					part1 = THRESH2_NO10;
	//					part2 = salary-THRESH2_NO10;
	//				}
	//			}
	//			break;
	//		case 3: {
	//				if (salary < THRESH3_NO10)
	//				{
	//					part1 = salary;
	//					part2 = 0.f;
	//				}
	//				else
	//				{
	//					part1 = THRESH3_NO10;
	//					part2 = salary-THRESH3_NO10;
	//				}
	//			}
	//			break;
	//		case 4: {
	//				if (salary < THRESH4_NO10)
	//				{
	//					part1 = salary;
	//					part2 = 0.f;
	//				}
	//				else
	//				{
	//					part1 = THRESH4_NO10;
	//					part2 = salary-THRESH4_NO10;
	//				}
	//			}
	//			break;
	//		default: break;
	//	}
	//	printf("The stereotype of the input is %d and the salary is %.2lf, here is the tax %.2lf\n", stereotype, salary, part1*0.15+part2*0.28);
	//	printf("Please re-enter the type and salary:\n");
	//}

	/* Chapter 7 Programming practice No.10 */
	// char c_veg_type;
	// double pound = 0.f;
	// const double PRICE_KOREAN = 1.25f;
	// const double PRICE_SWEETY = 0.65f;
	// const double PRICE_CARROT = 0.89f;
	// double cost_veg = 0.f;
	// double cost_tsp = 0.f;
	// printf("Please enter the type to buy and the pound you want:\n");
	// scanf("%c,%lf", &c_veg_type, &pound);
	// while (1)
	// {
	// 	double price = 0.f;
	// 	double discount = 0.f;
	// 	switch(c_veg_type) {
	// 		case 'a': price = PRICE_KOREAN; break;
	// 		case 'b': price = PRICE_SWEETY; break;
	// 		case 'c': price = PRICE_CARROT; break;
	// 		default: break;
	// 	}
	// 	cost_veg = price * pound;
	// 	if (cost_veg > 100.f) {
	// 		discount = cost_veg*0.05f;
	// 		cost_veg *= 0.95f;
	// 	}

	// 	if (pound <= 5.f)
	// 		cost_tsp = 3.50f;
	// 	else if (pound <= 20.f)
	// 		cost_tsp = 10.0f;
	// 	else
	// 		cost_tsp = 8.0f + (pound-20.f)*0.1f;
		
	// 	switch(c_veg_type) {
	// 		case 'a': printf("You want to buy korean "); break;
	// 		case 'b': printf("You want to buy sweety "); break;
	// 		case 'c': printf("You want to buy carrot "); break;
	// 		default: break;
	// 	}
	// 	printf("%.2lf pounds.\n", pound);
	// 	printf("The vegetable cost $%.2lf, the transportion cost $%.2lf and the total cost equals $%.2lf\n", cost_veg, cost_tsp, cost_veg+cost_tsp);
	// 	if (discount > 1e-5f)
	// 		printf("You have got a $%.2lf discount.\n", discount);
	// 	else
	// 		printf("There is no discount for the current bill.\n");
	// 	printf("Please re-enter the type to buy and the pound you want:\n");
	// 	scanf("%c,%lf", &c_veg_type, &pound);
	// 	if (c_veg_type=='q')
	// 		break;
	// }

	/* Chapter 6 Programming practice No.4 */
	//char c_input;
	//printf("Please enter a capital letter: ");
	//scanf("%c", &c_input);
	//do {
	//	//if (c_input>='a' && c_input <='z')
	//	if (islower(c_input))
	//	{
	//		c_input += 'A'-'a';
	//		break;
	//	}
	//	if (isupper(c_input))
	//		break;

	//	printf("Wrong input! Please reenter!\n");
	//} while (1==scanf("%c", &c_input));

	//int diff = c_input-'A';
	//int width = 2*diff+1;
	//int row = diff+1;
	//for (int i=0; i<row; ++i)
	//{
	//	for (int j=0; j<diff-i; ++j)
	//		printf(" ");

	//	for (int j=diff-i; j<(width-1)/2; ++j)
	//	{
	//		printf("%c", 'A'+j-diff+i);
	//	}
	//	for (int j=(width-1)/2; j<diff+i+1; ++j)
	//	{
	//		printf("%c", 'A'+i-j+(width-1)/2);
	//	}

	//	for (int j=diff+i+1; j<width; ++j)
	//		printf(" ");
	//	printf("\n");
	//}

	///* Chapter 6 Programming practice No.5 */
	//int top_limit = 0;
	//int bot_limit = 0;
	//printf("Please enter the bottom bound and upper bound: ");
	//scanf("%d %d", &bot_limit, &top_limit);
	//if (bot_limit >= top_limit)
	//{
	//	printf("Bad input format! Check it!\n");
	//	return 1;
	//}
	//printf("Integer\tSquare\t  Cubic\n");
	//for (int i=bot_limit; i<top_limit; ++i)
	//{
	//	printf("%6d\t%6d\t%6d\n", i, i*i, i*i*i);
	//}

	///* Chapter 6 Programming practice No.7 && No.8 */
	//double d_num1 = 0.f;
	//double d_num2 = 0.f;
	//printf("Please enter two double numbers: ");
	//while (2==scanf("%lf %lf", &d_num1, &d_num2))
	//{
	//	printf("The result: %6.2lf\n", diff_over_multiply(d_num1, d_num2));
	//}

	///* Chapter 6 Programming practice No.10 */
	//int lower_bound = 0;
	//int upper_bound = 0;
	//printf("Please enter lower and upper integer limits: ");
	//while (2==scanf("%d %d", &lower_bound, &upper_bound))
	//{
	//	if (lower_bound >= upper_bound) break;
	//	int sum = 0;
	//	for (int i=lower_bound; i<=upper_bound; ++i)
	//		sum += i*i;
	//	printf("The sums of the squares from %d to %d is %d\n", lower_bound*lower_bound, upper_bound*upper_bound, sum);
	//	printf("Enter next set of limits: ");
	//}

	///* Chapter 6 Programming practice No.11 */
	//double sum1 = 0.f;
	//double sum2 = 0.f;
	//int iter = 0;
	//printf("Please enter the number to iterate: ");
	//scanf("%d", &iter);
	//for (int i=1; i<=iter; ++i)
	//{
	//	double current_value = 1.f/i;
	//	sum1 += current_value;
	//	sum2 += current_value * (i%2 ? 1 : -1);
	//}
	//printf("sum1=%lf, sum2=%lf\n", sum1, sum2);

	///* Chapter 6 Programming practice No.12 */
	//const int ARRAY_SIZE = 8;
	//int i_array_power[ARRAY_SIZE];
	//for (int i=0; i<ARRAY_SIZE; ++i)
	//{
	//	if (0==i)
	//		i_array_power[i] = 1;
	//	else
	//		i_array_power[i] = 2*i_array_power[i-1];
	//}

	//int index = 0;
	//printf("Array value normal:\t");
	//do {
	//	printf("%3d ", i_array_power[index++]);
	//} while (index<ARRAY_SIZE-1);
	//printf("%3d\nArray value reversed:\t", i_array_power[index]);

	///* Chapter 6 Programming practice No.10 */
	//for (int i=0; i<ARRAY_SIZE-1; ++i)
	//	printf("%3d ", i_array_power[ARRAY_SIZE-i-1]);
	//printf("%3d\n", i_array_power[0]);

	/* Chapter 6 Programming practice No.13 */
	//const int ARRAY_SIZE = 8;
	//double d_array1[ARRAY_SIZE];
	//double d_array2[ARRAY_SIZE];
	//printf("Please enter the elements for the array:\n");
	//for (int i=0; i<ARRAY_SIZE; ++i)
	//{
	//	scanf("%lf", &d_array1[i]);
	//	d_array2[i] = d_array1[i];
	//}

	//for (int i=1; i<ARRAY_SIZE; ++i)
	//	d_array2[i] += d_array2[i-1];

	//printf("Array 1: ");
	//for (int i=0; i<ARRAY_SIZE; ++i)
	//	printf("%6.2lf ", d_array1[i]);
	//printf("\nArray 2: ");
	//for (int i=0; i<ARRAY_SIZE; ++i)
	//	printf("%6.2lf ", d_array2[i]);

	/* Chapter 6 Programming practice No.14 */
	//char str_input[100];
	//char str_output[100];
	//printf("Please enter one sentence to be processed: ");
	//gets(str_input);
	//printf("The original string is: %s\n", str_input);
	//int str_len = strlen(str_input);
	//for (int i=0; i<str_len; ++i)
	//	str_output[str_len-i-1] = str_input[i];
	//str_output[str_len] = '\0';

	//printf("The reversed string is: %s\n", str_output);
	/* Chapter 6 Programming practice No.15 & No.16 */
	//double money_init = 100.f;
	//double money_remained1 = money_init;
	//double money_remained2 = money_init;
	//double increase_rate1 = 0.10f;
	//double increase_rate2 = 0.05f;
	//int year = 1;
	//while (money_remained1 >= money_remained2)
	//{
	//	money_remained1 += money_init*increase_rate1;
	//	money_remained2 += money_remained2*increase_rate2;
	//	printf("After %2d year: Daphne-$%.2lf, Deirdre-%.2lf.\n", year++, money_remained1, money_remained2);
	//	if (money_remained1 < money_remained2)
	//		break;
	//}
	//printf("After %d year Deirdre will overtaken by Daphne.\n", --year);

	//for (int x=0; x<6; ++x)
	//{
	//	char start = 'F';
	//	for (int y=0; y<=x; ++y)
	//		printf("%c", start--);
	//	printf("\n");
	//}
	//printf("\n");
	//const int ARRAY_SIZE = 26;
	//char alpha_table[ARRAY_SIZE];
	//for (int i = 0; i < ARRAY_SIZE; ++i)
	//	scanf("%c", &alpha_table[i]);
	//for (int k = 0; k < ARRAY_SIZE; ++k)
	//	printf("%c", alpha_table[k]);
	//printf("\n");
	//char ch;

	//scanf("%c", &ch);
	//for (; ch!='g'; scanf("%c", &ch))
	//	putchar(ch);

	//do {
	//	scanf("%c", &ch);
	//	printf("%c", ch);
	//} while (ch != 'g');
	//scanf("%c", &ch);
	//while (ch != 'g')
	//{
	//	printf("%c", ++ch);
	//	scanf("%c", &ch);
	//}
	//double degree_fah = 0.f;
	//printf("Enter the Fahrenheit degree: ");
	//while (1 == scanf("%lf", &degree_fah))
	//{
	//	Temperatures(degree_fah);
	//	printf("Enter the Fahrenheit degree: ");
	//}
	//printf("Done!\n");
	
	//float height_cm = 0.f;
	//const float cm_per_inch = 2.54f;
	//const float cm_per_foot = 30.48f;
	//printf("Enter a height in centimeters: ");
	//scanf("%f", &height_cm);
	//int ft_part = 0;
	//while (height_cm > 0)
	//{
	//	ft_part = (int)(height_cm/cm_per_foot);
	//	printf("%f cm = %d feet, %.1f inches.\n", height_cm, ft_part, (height_cm-ft_part*cm_per_foot)/cm_per_inch);
	//	printf("Enter a height in centimeters(<=0 to quit): ");
	//	scanf("%f", &height_cm);
	//}
	//printf("Bye!\n");
	//int days = 0;
	//int weeks = 0;
	//const int days_per_week = 7;
	//printf("Please input days: ");
	//scanf("%d", &days);
	//while (days >= 0)
	//{
	//	printf("%d days are %d weeks, %d days.\n", days, days/days_per_week, days%days_per_week);
	//	printf("Please input days: ");
	//	scanf("%d", &days);
	//}
	//printf("Done!\n");
	//int max_signed_int = 0x7fffffff;
	//int min_signed_int = 0x80000000;
	//printf("max_signed_int=%d, %d, %d\n", max_signed_int, max_signed_int+1, max_signed_int+2);
	//printf("min_signed_int=%d, %d, %d\n", min_signed_int, min_signed_int-1, min_signed_int-2);
	//unsigned int max_unsigned_int = 0xffffffff;
	//unsigned int min_unsigned_int = 0x00;
	//printf("max_unsigned_int=%d, %d, %d\n", max_unsigned_int, max_unsigned_int+1, max_unsigned_int+2);
	//printf("min_unsigned_int=%d, %d, %d\n", min_unsigned_int, min_unsigned_int-1, min_unsigned_int-2);

	//float max_signed_float = 3.4e38;
	//float min_signed_float = 1.4e-45;
	//printf("max_signed_float=%e, %e\n", max_signed_float, max_signed_float*10);
	//printf("min_signed_float=%e, %e\n", min_signed_float, min_signed_float/2);

	//printf("\aStartled by the sudden sound, Sally shouted,\"By the Great Pumpkin, what was that!\"\n");

	//char ascii_char;
	//printf("input a number for ascii char: ");
	//scanf("%d", &ascii_char);
	//printf("ascii_char=%c\n", ascii_char);

	//double year_time = 3.156e7;
	//int age = 0;
	//printf("type your age: ");
	//scanf("%d", &age);
	//printf("%.4f s for your age.\n", year_time*age);

	//printf("input quaters for water weight: ");
	//float weight = 0.f;
	//double atom_num = 3.0e-23;
	//scanf("%f", &weight);
	//printf("Number of water atom: %f\n", weight*950.f/atom_num);

	//printf("input your height: ");
	//float height = 0.f;
	//scanf("%f", &height);
	//printf("height in inch is %4.2f\n", height/2.54f);
	//printf("The input is %f or %e\n", height, height);

	printf("Done!\n");

	return 0;
}

void show_current_time(void)
{
	char buff[50];
	struct tm tm_current;
	// localtime may not thread-safe
	// https://en.cppreference.com/w/c/chrono/localtime
	localtime_r(&(time_t){time(NULL)}, &tm_current);

	// https://en.cppreference.com/w/c/chrono/strftime
	if (strftime(buff, sizeof(buff), "%c", &tm_current)) {
		printf("%s\n", buff);
	} else {
		printf("strftime failed!\n");
	}
}

/**
 * Definition of the declared functions
 * Description:
 * 	For compute, how to save 11 22 33 44 in the storage?
 * 	Big-Endian means high bit first
 * 	Little-Endian means low bit first
 * 	Since in common address value increase
 * 	So the result is 11 22 33 44 on big endian machine
 * 	and 44 33 22 11 on little endian machine
 */
void check_system_endian(void)
{
	union endian_check
	{
		int iNum;
		char ch;
	} endian_test;
	endian_test.iNum = 1;

	/* Date and time when running the program */
	show_current_time();

	/* 32-bit machine or 64-bit machine */
#ifdef __x86_64__
	printf("64-bits machine.\n");
#elif __i386__
	printf("32-bits machine.\n");
#endif

	/* Big-endian machine or little-endian machine */
	if (1==endian_test.ch)
	{
		printf("The system endian mode is Little-Endian.\n");
	}
	else
	{
		printf("The system endian mode is Big-Endian.\n");
	}
	return ;
}

int my_add(int num1, int num2)
{
	return (num1+num2);
}

float cubic_float (float num)
{
	return num*num*num;
}

void Temperatures(double degree_fah)
{
	const double adj_kel = 273.16f;
	const double scale = 1.8f;
	const double adjust = 32.0f;

	double degree_cel = scale*degree_fah+adjust;
	printf("Temperature is %.2f in Fahrenheit, %.2f in Celsius, %.2f in Kelvin\n", degree_fah, degree_cel, degree_cel+adj_kel);
}

double diff_over_multiply(double num1, double num2)
{
	return (num1-num2)/(num1*num2);
}

void show_usage(void)
{
	printf("****************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action\n");
	printf("1) $%.2f/hr\t\t\t2) $%.2f/hr\n", PAY_RATE1, PAY_RATE2);
	printf("3) $%.2f/hr\t\t\t4) $%.2f/hr\n", PAY_RATE3, PAY_RATE4);
	printf("5) quit\n");
	printf("****************************************\n");
}

void test_workspace(void)
{
	check_system_endian();
	printf("Type char has %lu bytes\n", sizeof(char));
	printf("Type short has %lu bytes\n", sizeof(short));
	printf("Type int has %lu bytes\n", sizeof(int));
	printf("Type float has %lu bytes\n", sizeof(float));
	printf("Type double has %lu bytes\n", sizeof(double));

	// automatic type conversion
	if (-1L < 1U)
	{
		printf("sizeof(unsigned int)=%lu\nsizeof(signed long int)=%lu\n",
		       sizeof(unsigned int), sizeof(signed long int));
		printf("\'-1L<1U\' since unsigned int is promoted to signed long type!\n");
	}
	if (-1L > 1UL)
	{
		printf("sizeof(signed long int)=%lu\nsizeof(unsigned long int)=%lu\n",
		       sizeof(signed long int), sizeof(unsigned long int));
		printf("\'-1L>1UL\' since signed long int is promoted to unsigned long type!\n");
	}

	// char type
	char ch = 'A';
	printf("char constant occupies %d bytes while char variable %d bytes\n", sizeof('A'), sizeof(ch));
	printf("what does \\0x6e like? \x6e, 0x6e=%c\n", 0x6e);

	// float storage
	// e.g. 32-bit float number
	// 1-bit sign + 8-bit exponent + 23-bit mantissa
	// 0.5f --> 0 0111 1110 0...0 --> 3f 00 00 00
	float f_num = 0.5f;
	float *p_f = &f_num;
	printf("float f_num=%f\n", *p_f);
	char *p_iff = (char *)p_f;
	for (int i=3; i>=0; i--)
	{
		printf("%02x ", *(p_iff+i));
	}
	printf("\n");

	// int num 5 in storage is 00 00 00 05
	// which can be interpreted as float (1*2^-21+1*2^-23)*2^-127 ~= +0
	int i_num = 5;
	printf("int i_num=%d\n", i_num);
	int *p_i = &i_num;
	char *p_ffi = (char *)p_i;
	for (int i=3; i>=0; i--)
	{
		printf("%02x ", *(p_ffi+i));
	}
	int vf = printf("\nHello world!\n");
	printf("return value of the last printf statement %d\n", vf);
}

long fibonacci_recursively(int n)
{// Recursively
	if (n<3)
	{
		return 1;
	}
	return fibonacci_recursively(n-1)+fibonacci_recursively(n-2);
}

long fibonacci_iteratively(int n)
{// Iterately
	if (n<3)
	{
		return 1;
	}
	long res = 0;

	int *plog = (int *)malloc(sizeof(int)*n);
	*(plog) = *(plog+1) = 1;

	for (int i=2; i<n; i++)
	{
		plog[i] = plog[i-1]+plog[i-2];
	}
	res = plog[n-1];
	free(plog);

	return res;
}

long fibonacci_loop(int n)
{
	if (n<3)
	{
		return 1;
	}

	long res = 0;
	long last = 1;
	long prev = 1;
	for (int i=3; i<=n; i++)
	{
		res = prev+last;
		prev = last;
		last = res;
	}

	return res;
}

void test_fibonacci(int n)
{
	// 1 1 2 3 5 8 13 21 34 55

	int iter = 5000;
	clock_t start_time, end_time;

	start_time = clock();
	while (--iter>0)
	{
		fibonacci_recursively(n);
	}
	for (int i=1; i<=n; i++)
	{
		printf("F(%u)=%lu\t", i,fibonacci_recursively(i));
	}
	putchar('\n');
	end_time = clock();
	printf("Recursive solution cost %6.4f ms\n",(double)(end_time-start_time)/CLOCKS_PER_SEC*1000.f);

	iter = 5000;
	start_time = clock();
	while (--iter>0)
	{
		fibonacci_iteratively(n);
	}
	for (int i=1; i<=n; i++)
	{
		printf("F(%u)=%lu\t", i,fibonacci_iteratively(i));
	}
	putchar('\n');
	end_time = clock();
	printf("Iterative solution cost %6.4f ms\n",(double)(end_time-start_time)/CLOCKS_PER_SEC*1000.f);

	iter = 5000;
	start_time = clock();
	while (--iter>0)
	{
		fibonacci_loop(n);
	}
	for (int i=1; i<=n; i++)
	{
		printf("F(%u)=%lu\t", i,fibonacci_loop(i));
	}
	putchar('\n');
	end_time = clock();
	printf("Loop solution cost %6.4f ms\n",(double)(end_time-start_time)/CLOCKS_PER_SEC*1000.f);
}

#define BACKSPACE ('\b')
void text_cnt(void)
{
	char c;
	char prev;
	long n_chars = 0;
	long n_words = 0;
	long n_lines = 0;
	int p_lines = 0;
	int inword = 0;
	char input[500];

	printf("[Enter text to be analyzed(Ctl-C to terminate):]\n");
	while ((c=getchar())!=EOF)
	{
		if (BACKSPACE==c)
		{
			putchar(BACKSPACE);
		}
		if (!isspace(c))
		{
			input[n_chars++] = c;
		}
		if ('\n'==c)
		{
			++n_lines;
		}
		if (!isspace(c)&&!inword)
		{
			++n_words;
			inword = 1;
		}
		if (isspace(c)&&inword)
		{
			inword = 0;
		}
	}

	input[n_chars] = '\0';
	printf("\ncaptured text: %s\n", input);
	printf("characters=%ld, words=%ld, lines=%ld\n", n_chars, n_words, n_lines);
}
