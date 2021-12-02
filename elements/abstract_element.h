#pragma once
#include <string>
#include <iomanip>

namespace Elements {
    class Element {
    protected:
        const std::string type;
        const int pin;
        const std::string direction;
        mutable int val;
        std::string workdir;
        std::string state_0 = "None";
        std::string state_1 = "None";
    //
    public:
        int GetStatus() const;
        std::string GetWorkdir() const;
        friend std::ostream& operator<< (std::ostream& os, const Element& elem) {
            return elem.print(os, elem.state_1, elem.state_0);
        }
    //
    protected:
        Element(const std::string& e_type, int e_pin,
                const std::string& e_direction, int value);
        void WriteValue() const;
        void WriteDirection() const;
        int Action() const;
        virtual std::ostream& print(std::ostream& os, const std::string& true_cond,
                                    const std::string& false_cond) const {
            os << this->type << " gpio"  << this->pin << " value:" << this->GetStatus();
            os << " [" << (this->val? true_cond : false_cond) << "]";
            return os;
        };
    };
}

