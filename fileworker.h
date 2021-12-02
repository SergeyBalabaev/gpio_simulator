#pragma once
#include <map>
#include <iostream>
#include <fstream>
//

enum COMMAND {
	MKDIR, RMDIR, MKFILE, RMFILE, SIZE
};

const std::map<COMMAND, std::string> commands = {
	{MKDIR, "mkdir -p "}, 
	{RMDIR, "rm -r "},
	{MKFILE, "touch "},
	{RMFILE, "rm "}, 
	};

void Filesystem(COMMAND command, std::string name);