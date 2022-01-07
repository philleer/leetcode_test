#include <stdio.h>
#include <string>
#include <gflags.h>
#include <spdlog/spdlog.h>
#include "mylog.h"

DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");
DEFINE_string(languages, "english,french,german",
			  "comma-separated list of languages to offer in the 'lang' menu");

int main(int argc, char *argv[])
{
	spdlog::set_level(spdlog::level::warn);
	spdlog::info("Hello world!");
	spdlog::warn("I am string multiply function {:08d}", 12);
	spdlog::error("some error message with arg: {}", 1);
	spdlog::critical("when fatal encountered, exit!");
	gflags::ParseCommandLineFlags(&argc, &argv, true);

	if (FLAGS_big_menu)
		FLAGS_languages += ",klingon";
	if (FLAGS_languages.find("finnish")==std::string::npos)
		printf("All supported languages: %s\n", FLAGS_languages.c_str());
	else
		printf("Modified languages: %s\n", FLAGS_languages.c_str());

	double nc = 0;
	++nc;
	printf("Value of EOF is %d, %.0f\n", EOF, nc);

	return 0;
}
