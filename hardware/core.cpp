#include <signal.h>
//
#include "core.h"
#include "signal_handler.h"

namespace Cores {
    class Core;

    void Ctrl_C_cores(int val) {
       std::cout << "\n___Core simulating thread [PID " << getpid() << "] terminated___\n";
       Ctrl_C(0);
    }

    Core::Core() : num(ACTIVE++) {
        std::string path = PATH + "thermal_zone" + std::to_string(num);
        Filesystem(MKDIR, path);
        for(auto& elem : {"/temp"}) {
            Filesystem(MKFILE, path + elem);
        }
        this->th_temp_updater = std::thread(th_UpdateTemp, this);
    }

    Core::~Core() {
        this->th_temp_updater.join();
    }

    void Core::th_UpdateTemp(Core* _this) {
        signal(SIGINT, Ctrl_C_cores);
        while(Globals::SIMULATING)
            _this->UpdateTemp();
    }

    void Core::UpdateTemp() {
        this->temp = (random() % 4000)/100.0 + 30.0;
        std::string command = "echo " + std::to_string(this->temp) +
                                " > " + Cores::PATH + "thermal_zone" + std::to_string(this->num) + "/temp";
        system(command.c_str());
    }

    double Core::GetTemp() const {
        return this->temp;
    }
}
