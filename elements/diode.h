#pragma once
#include "output_element.h"


namespace Elements {
    class Diode: public OutputElement {
    public:
        Diode() = delete;
        Diode(int pin) : OutputElement("Diode", pin, 0) {
            this->state_0 = "\u001b[0m"" ◆ ";
            this->state_1 = "\u001b[32m"" ◆ ""\u001b[0m";
        };
        void Paint();
    };
}

