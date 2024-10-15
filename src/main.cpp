#include <iostream>
#include "simulation.h"


int main(int argc, char ** argv){
	std::cout  << "Start MPM solver" << std::endl ; 

	int simulationSteps = 100 ; 

	Simulation simulation(simulationSteps) ; 
	simulation.initialize() ; 
	simulation.loop() ; 
	simulation.finalize() ; 

	std::cout << "End MPM solver "<< std::endl ; 
	return 0 ; 
}
