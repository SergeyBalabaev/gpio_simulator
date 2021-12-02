#pragma once
#include <string>
//
#include "globals.h"
//

namespace GPIO {
    static const std::string PATH = Globals::WORKDIR + "class/gpio/";

    void Create(int pin);

    void Remove(int pin);
}
///
