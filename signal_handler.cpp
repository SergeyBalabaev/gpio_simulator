#include "signal_handler.h"
#include "fileworker.h"
#include "globals.h"

#include <iostream>
#include <unistd.h>

void Ctrl_C(int val) {
    std::cout << "\n_____SIGINT received_____\n";
    Globals::SIMULATING = Globals::FIFO_SIMULATING = 0;
    Filesystem(RMDIR, Globals::WORKDIR);
    exit(0);
}

