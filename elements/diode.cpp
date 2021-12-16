#include <iostream>

#include "diode.h"

namespace Elements {
    void Diode::Paint() {
        std::cout << (this->val? "\u001b[32m"" ◆ ""\u001b[0m" : "\u001b[0m"" ◆ ");
    }
}
