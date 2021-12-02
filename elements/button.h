#pragma once
#include "input_element.h"

namespace Elements {
    class Button: public InputElement {
    public:
        Button() = delete;
        Button(int pin) : InputElement("Button", pin, 1) {
            this->state_0 = "pressed";
            this->state_1 = "not pressed";
        };
    };
}

