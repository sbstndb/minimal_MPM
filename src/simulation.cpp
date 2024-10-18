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
	// interpolation

	computeInterpolation() ; 

	// work
}

void Simulation::finalize(){
        std::cout << "simuation finalize" << std::endl ;
	
	// cuda stuff
}

void Simulation::addBody(int nParticles_){
	body.addBody(nParticles_) ; 
}

void Simulation::addGrid(float nx, float ny, float nz, float h){
	grid.addGrid(nx, ny, nz, h);	
}

void Simulation::computeInterpolation(){
	solver.interpolation.weightInterp(
			body.particles.d_x, body.particles.d_y, body.particles.d_z, 
			grid.d_x, grid.d_y, grid.d_z,
			body.particles.d_node_x, body.particles.d_node_y, body.particles.d_node_z,
			body.particles.d_weights, 
			body.particles.nParticles,
			grid.nx, grid.ny, grid.nz, grid.h);
}	


