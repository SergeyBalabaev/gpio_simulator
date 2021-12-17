#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//
#include "pipe.h"
#include "fileworker.h"

#include <iostream>
#include <errno.h>
namespace Pipes
{
    Pipe::Pipe(const std::string &name) : name(name)
	{
        Filesystem(MKDIR, Pipes::PATH);
        if (mkfifo((Pipes::PATH + this->name).c_str(), 0666) == -1) {
            std::cout << "Warning: \"" << this->name << "\" was not created!" << std::endl;
        } else {
            std::cout << "\"" << name << "\" pipe created successfully!" << std::endl;
        }
	}

	Pipe::~Pipe()
	{
		if (unlink((Pipes::PATH + this->name).c_str()) != -1)
			std::cout << "\"" << name << "\" pipe removed successfully!" << std::endl;
	}
}
