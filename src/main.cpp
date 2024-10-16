#include <iostream>
#include "simulation.h"


int main(int argc, char ** argv){
	std::cout  << "Start MPM solver" << std::endl ; 

	int simulationSteps = 4 ; 

	// maybe better ise simulation.step(100); ? 
	Simulation simulation(simulationSteps) ; 
	simulation.initialize() ; 


	simulation.addGrid(1.0, 1.0, 1.0, 0.1) ; 
	simulation.addBody(10000) ; 

//	simulation.setBake("Bake_folder", 10) ;  // every 10 iterations for example ? 

	simulation.run() ; 


//	simulation.loop() ; 
	simulation.finalize() ; 

	std::cout << "End MPM solver "<< std::endl ; 
	return 0 ; 
}
