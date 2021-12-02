#pragma once
#include "abstract_element.h"

namespace Elements {
    class OutputElement: public Element {
    public:
        int Invert() {
            return Element::Action();
        };
    protected:
        OutputElement() = delete;
        OutputElement(const std::string elem_type, int elem_pin, const int start_val)
                         : Element(elem_type, elem_pin, "out", start_val){};
    };
}
