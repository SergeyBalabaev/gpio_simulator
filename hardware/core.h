#pragma once
#include <iostream>
#include <thread>
//
#include "globals.h"
#include "fileworker.h"

namespace Cores {
    static volatile unsigned int ACTIVE = 0;
    static const std::string PATH = Globals::WORKDIR + "class/thermal/";

    void Ctrl_C_cores(int val);

    class Core {
    private:
        double temp;
        std::thread th_temp_updater;
    public:
        const int num;
        //
        Core();
        ~Core();
        void UpdateTemp();
        static void th_UpdateTemp(Core* _this);
        double GetTemp() const;
        friend std::ostream& operator<< (std::ostream& os, const Core& c) {
            os << "Core" << c.num << " [temp:" << c.GetTemp() << "] ";
            return os; 
        }
    };
}
