#pragma once
#include "abstract_element.h"

namespace Elements {
    class InputElement: public Element {
    public:
        int Action() {
            return Element::Action();
        };
    protected:
        InputElement() = delete;
        InputElement(const std::string elem_type, int elem_pin, const int start_val)
                         : Element(elem_type, elem_pin, "in", start_val){};
    };
}
