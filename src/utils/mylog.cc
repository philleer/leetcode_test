#include "mylog.h"

void log_runtime_info(void)
{
	printf("[%s %s] %s: %s: %d\n", __DATE__, __TIME__, __FILE__, __func__, __LINE__);
}

void log_init(const int argc, char *argv[])
{
	char executable_main_path[200];
	if (NULL==getcwd(executable_main_path, sizeof(executable_main_path)))
	{
		printf("ERROR: Cannot obtain current working directory!\n");
		exit(EXIT_FAILURE);
	}
	char log_path[200];
	sprintf(log_path, "%s/logging", executable_main_path);
	if (-1==access(log_path, F_OK))
	{
		if (-1==mkdir(log_path, S_IRUSR | S_IWUSR | S_IXUSR))
		{
			printf("FATAL ERROR: %s does not exist and cannot mkdir!!!\n", log_path);
			exit(EXIT_FAILURE);
		}
		printf("Directory %s is created.\n", log_path);
	}
}