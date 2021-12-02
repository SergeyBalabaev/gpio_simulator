#include "fileworker.h"
//

void Filesystem(COMMAND type, std::string command) {
    std::string cmd = commands.at(type) + std::move(command);
	system(cmd.c_str());
}
