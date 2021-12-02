#pragma once
#include <iostream>
//
#include "globals.h"

namespace FIFO {

    static const std::string PATH = Globals::WORKDIR + "class/gpio/";
    
    void Read(const std::string& name, bool is_export);

}
