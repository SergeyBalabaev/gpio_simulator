#pragma once
#include "output_element.h"


namespace Elements {
    class Diode: public OutputElement {
    public:
        Diode() = delete;
        Diode(int pin) : OutputElement("Diode", pin, 0) {
            this->state_0 = "light off";
            this->state_1 = "light on";
        };
    };
}

