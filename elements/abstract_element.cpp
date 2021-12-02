#include "abstract_element.h"
#include "../hardware/gpio.h"
#include <iostream>
#include <fstream>
/////////////////////
namespace Elements {

    Element::Element(const std::string& e_type, int e_pin,
            const std::string& e_direction, int value) :
                    type(e_type),
                    pin(e_pin),
                    direction(e_direction) {
        this->val = value;
        this->workdir = GPIO::PATH + "gpio" + std::to_string(pin);
        GPIO::Create(this->pin);
        WriteValue();
        WriteDirection();
        std::cout << "Assigned gpio" << this->pin << " to element: " << this->type << std::endl;
    };

    int Element::GetStatus() const {
        std::ifstream fin(workdir+"/value");
        std::string str;
        fin >> this->val;
        return this->val;
    };

    std::string Element::GetWorkdir() const {
        return this->workdir;
    };

    void Element::WriteValue() const {
        std::ofstream f_value(workdir + "/value");
        f_value << this->val;
        f_value.close();
    }

    void Element::WriteDirection() const {
        std::ofstream f_direction(this->workdir + "/direction");
        f_direction << this->direction;
        f_direction.close();
    }

    int Element::Action() const {
        this->val = !this->GetStatus();
        WriteValue();
        return this->val;
    }

}
/////////////////////
