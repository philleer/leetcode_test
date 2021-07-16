#include <math.h>
#include <stdio.h>

int my_add(int num1, int num2);

int main(const int argc, char * argv[])
{
	int num1 = 0;
	int num2 = 0;
	printf("Please input the two numbers:\n");
	scanf("%d,%d", &num1, &num2);
	printf("The addition of the given num is: %d\n", my_add(num1, num2));

	return 0;
}

int my_add(int num1, int num2) {
	return (num1+num2);
}
