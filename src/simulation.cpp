#include "simulation.h"
#include <iostream>


Simulation::Simulation(int totalSteps_) : totalSteps(totalSteps_) {
	// il faut ajouter tout le reste ..
}

Simulation::~Simulation(){
}

void Simulation::initialize(){
	std::cout << "simuation initialize" << std::endl ;
	currentSteps = 0 ; 
	currentTime = 0.0 ; 

}

void Simulation::run(){
        std::cout << "simuation run" << std::endl ;
	for (int i = 0 ; i < totalSteps ; i++){
		Simulation::loop();
	}
}

void Simulation::loop(){
	std::cout << " In a loop !! " << std::endl ; 
	// work
}

void Simulation::finalize(){
        std::cout << "simuation finalize" << std::endl ;
	
	// cuda stuff
}

void Simulation::addBody(int nParticles_){
	body.addBody(nParticles_) ; 
}


