/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <cstring>
#include "SciEng/SciEngEnvironment.h"
#include "examples/ch9/Acme130_VS_GI_GC.h"
#include "examples/ch9/VoltyMetrics_VM_GI.h"
#include "examples/ch9/GPIBController_GIS.h"
#include "examples/ch9/GPIBInstrumentSimulation.h"
#include "examples/ch9/Acme130Simulation.h"
#include "examples/ch9/VoltyMetricsSimulation.h"
#include "examples/ch9/IVTester.h"
#include "examples/ch9/SimulatorFactory.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

class MySimulators :
    public SimulatorFactory {
public:
    virtual GPIBInstrumentSimulation* 
        create(const char* device_name, ExperimentSimulation& exp) const;
};


GPIBInstrumentSimulation*
MySimulators::create(const char* device_name, ExperimentSimulation& exp) const {
    GPIBInstrumentSimulation* sim_p;
    if (strcmp(device_name, "Acme130_VS_GI_GC") == 0) {
        sim_p = new Acme130Simulation(exp);
    }
    else if (strcmp(device_name, "VoltyMetrics_VM_GI") == 0) {
        sim_p = new VoltyMetricsSimulation(exp);
    }
    else throw "Simulator for specified device not available";
    return sim_p;
}


int main() {
  {

  MySimulators simulators;
  GPIBController_GIS gpib(simulators);


  Acme130_VS_GI_GC supply(gpib, 12);
  VoltyMetrics_VM_GI meter(gpib, 13);
  
  IVTester iv(supply, meter);
  double v_step = 1.0;
  for (int i = 0; i < 10; i++) {
    cout << iv.current(v_step * i) << endl;
}

  }
  {

  try { 
    MySimulators simulators;
    GPIBController_GIS gpib(simulators);
    Acme130_VS_GI_GC supply(gpib, 12);
    VoltyMetrics_VM_GI meter(gpib, 13);

    IVTester iv(supply, meter);
    double v_step = 1.0;
    for (int i = 0; i < 10; i++) {
        cout << iv.current(v_step * i) << endl;
    }
} catch(const SciEngErr& e) {
    cerr << e << endl;
}

  }
  return 0;
}
