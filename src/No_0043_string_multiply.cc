#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h> // S_IRUSR
#include <string>
#include <gflags.h>
//#include "3rdparty/glog/src/glog/logging.h"

DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");
DEFINE_string(languages, "english,french,german",
			  "comma-separated list of languages to offer in the 'lang' menu");

void glog_init(const int argc, char *argv[]);

int main(int argc, char *argv[])
{
	printf("Hello world! I am string multiply function.\n");
	gflags::ParseCommandLineFlags(&argc, &argv, true);
	glog_init(argc, argv);

	if (FLAGS_big_menu)
		FLAGS_languages += ",klingon";
	if (FLAGS_languages.find("finnish")==std::string::npos)
		printf("All supported languages: %s\n", FLAGS_languages.c_str());
	else
		printf("Modified languages: %s\n", FLAGS_languages.c_str());
	//LOG(WARNING) << "glog works finely!";

	//google::ShutdownGoogleLogging();
	return 0;
}

void glog_init(const int argc, char *argv[])
{
	char executable_main_path[200];
	getcwd(executable_main_path, sizeof(executable_main_path));
	std::string log_path(executable_main_path);
	log_path = log_path.substr(0, log_path.rfind("/")+1) + "logging";

	//if (-1==access(log_path.c_str(), F_OK))
	//{
	//	if (-1==mkdir(log_path.c_str(), S_IRUSR | S_IWUSR | S_IXUSR))
	//	{
	//		printf("FATAL ERROR: %s does not exist and cannot mkdir!!!\n", log_path.c_str());
	//		exit(EXIT_FAILURE);
	//	}
	//	printf("Directory %s is created.\n", log_path.c_str());
	//}

	//google::InitGoogleLogging(argv[0]);
	//char log_level_path[100];
	//sprintf(log_level_path, "%s/INFO_", log_path.c_str());
	//google::SetLogDestination(google::GLOG_INFO, log_level_path);
	//sprintf(log_level_path, "%s/WARNING_", log_path.c_str());
	//google::SetLogDestination(google::GLOG_INFO, log_level_path);
	//sprintf(log_level_path, "%s/ERROR_", log_path.c_str());
	//google::SetLogDestination(google::GLOG_INFO, log_level_path);
	//sprintf(log_level_path, "%s/FATAL_", log_path.c_str());
	//google::SetLogDestination(google::GLOG_INFO, log_level_path);
	//google::SetLogFilenameExtension("log");
	//FLAGS_minloglevel = google::WARNING;
	//FLAGS_colorlogtostderr = true;
	//FLAGS_alsologtostderr = true;
	//FLAGS_max_log_size = 100;
	//google::InstallFailureSignalHandler();
}
