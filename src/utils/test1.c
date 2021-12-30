#include <stdio.h>
#include "utils/test1.h"

void string_add(void)
{
	printf("[%s %s] %s: %s: %d\n", __DATE__, __TIME__, __FILE__, __func__, __LINE__);
}
