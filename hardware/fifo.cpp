#include <fstream>
//
#include "fifo.h"
#include "gpio.h"

namespace FIFO {
    void Read(const std::string& name, bool is_export) {
        while(Globals::FIFO_SIMULATING)
        {
            std::ifstream fin (PATH + name, std::ios_base::in);
            int pin;
            if(fin)
            {
                fin >> pin;
                if(is_export)
                    GPIO::Create(pin);
                else
                    GPIO::Remove(pin);
            }
        }
    }
}
