#include <iostream>
#include "body.h"


Particles::Particles(){};

void Particles::allocateParticles(int nP_){
	nParticles = nP_ ; 
	// allocation without reserve
	// reserve enables emmiter : we SHOULD implement allocation with reserve in the future. 
	// allocation

	cudaMalloc((void**)&d_x, nP_ * sizeof(float)) ; 
        cudaMalloc((void**)&d_y, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_z, nP_ * sizeof(float)) ;

        cudaMalloc((void**)&d_vx, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_vy, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_vz, nP_ * sizeof(float)) ;

        cudaMalloc((void**)&d_mass, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_volume, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_density, nP_ * sizeof(float)) ;

        cudaMalloc((void**)&d_sig_xx, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_sig_yy, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_sig_zz, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_sig_xy, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_sig_xz, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_sig_yz, nP_ * sizeof(float)) ;


        cudaMalloc((void**)&d_eps_xx, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_eps_yy, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_eps_zz, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_eps_xy, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_eps_xz, nP_ * sizeof(float)) ;
        cudaMalloc((void**)&d_eps_yz, nP_ * sizeof(float)) ;

        cudaMalloc((void**)&d_weights, nP_ * 8 * sizeof(float)) ; // hardcoded for LINEAR case ONLY !!!! may induce bugs. 

//        cudaMalloc((void**)&d_phase, nP_ * sizeof(float)) ;


} ; 

Particles::~Particles(){

	nParticles = 0 ; 

	cudaFree((void*)d_x);
        cudaFree((void*)d_y);
        cudaFree((void*)d_z);

        cudaFree((void*)d_vx);
        cudaFree((void*)d_vy);
        cudaFree((void*)d_vz);

        cudaFree((void*)d_mass);
        cudaFree((void*)d_volume);
        cudaFree((void*)d_density);

        cudaFree((void*)d_sig_xx);
        cudaFree((void*)d_sig_yy);
        cudaFree((void*)d_sig_zz);
        cudaFree((void*)d_sig_xy);
        cudaFree((void*)d_sig_xz);
        cudaFree((void*)d_sig_yz);

        cudaFree((void*)d_eps_xx);
        cudaFree((void*)d_eps_yy);
        cudaFree((void*)d_eps_zz);
        cudaFree((void*)d_eps_xy);
        cudaFree((void*)d_eps_xz);
        cudaFree((void*)d_eps_yz);

        cudaFree((void*)d_weights);

        cudaFree((void*)d_phase);
};


Body::Body(){
	std::cout<< " Constructor body " << std::endl ; 
}; 
Body::~Body(){
        std::cout<< " destructor body " << std::endl ;

};


void Body::addBody(int nParticles_){
	particles.allocateParticles(nParticles_);
	nBodies++;
};


