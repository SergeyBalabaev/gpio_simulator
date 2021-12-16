#pragma once
#include "input_element.h"

namespace Elements {
    class Button: public InputElement {
    public:
        Button() = delete;
        Button(int pin) : InputElement("Button", pin, 1) {
            this->state_0 = "\u001b[32m""Pressed""\u001b[0m";
            this->state_1 = "\u001b[0m""Not Pressed";
        };
    };
}

