#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
//
#include <future>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
//
#include "hardware/fifo.h"
#include "hardware/gpio.h"
#include "hardware/pipe.h"
#include "hardware/core.h"
//
#include "elements/diode.h"
#include "elements/button.h"
//
#include "fileworker.h"
#include "globals.h"
#include "signal_handler.h"
using namespace std;

int main()
{
	signal(SIGINT, Ctrl_C);				// SIGINT handler
	//////////////////////
	Pipes::Pipe exp("export");					// make export pipe
	Pipes::Pipe unexp("unexport");				// make unexport pipe
	vector<future<void>> futures;							// Magic [Store async futures]
	futures.push_back(async(FIFO::Read, exp.name, true));		// Magic [Call async function for inspecting 'export' pipe]
	futures.push_back(async(FIFO::Read, unexp.name, false));	// Magic [Call async function for inspecting 'unexport' pipe]
	try
	{
		// Insert assigment commands below
        Cores::Core c0, c1, c2, c3;
        Elements::Diode d0(2), d1(3), d2(4), d3(5);
        Elements::Button b0(6), b1(7), b2(8);
		// Simulating actions below
        for(;Globals::SIMULATING; usleep(2500000u)) {
            cout << c0 << endl << c1 << endl << c2 << endl << c3 << endl << endl;
            cout << d0 << endl << d1 << endl << d2 << endl << d3 << endl << endl;
            cout << b0 << endl << b1 << endl << b2 << endl << endl;
            for (Elements::Diode* d : {&d0, &d1, &d2, &d3})
                d->Paint();
            cout << endl;
		};
	}
	catch(exception& re) {
		cout << re.what() << endl;
		kill(getpid(), SIGINT);		// self-destructing if catched exception
	}
	return 0;
}
