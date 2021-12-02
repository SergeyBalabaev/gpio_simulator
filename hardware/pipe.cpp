#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//
#include "pipe.h"
#include "fileworker.h"

namespace Pipes
{
    Pipe::Pipe(const std::string &name) : name(name)
	{
		if (mkfifo((Pipes::PATH + this->name).c_str(), 0666) == -1)
            Filesystem(COMMAND::RMDIR, Pipes::PATH + this->name);
		std::cout << "\"" << name << "\" pipe created successfully!" << std::endl;
	}

	Pipe::~Pipe()
	{
		if (unlink((Pipes::PATH + this->name).c_str()) != -1)
			std::cout << "\"" << name << "\" pipe removed successfully!" << std::endl;
	}
}
