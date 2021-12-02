#pragma once
#include <iostream>
//
#include "globals.h"

namespace Pipes {
	const std::string PATH = Globals::WORKDIR + "class/gpio/";
	
	class Pipe
	{
	public:
		const std::string name;
		//
		Pipe() = delete;
        Pipe(const std::string& name);
		~Pipe();
	};
}
