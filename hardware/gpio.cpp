#include "gpio.h"
#include "fileworker.h"
using namespace std;
//
namespace GPIO {

    void Create(int pin) {
        string path = PATH + "gpio" + to_string(pin);
        Filesystem(MKDIR, path);
        for (auto& elem : {"/value", "/direction"}) {
            Filesystem(MKFILE, path + elem);
        }
        cout << "gpio" << pin << " created successfully!" << endl;
    }

    void Remove(int pin) {
        Filesystem(RMDIR, PATH + "gpio" + to_string(pin));
        cout << "gpio" << pin << " removed successfully!" << endl;
    }
}
