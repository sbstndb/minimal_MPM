#ifndef BODY_H
#define BODY_H

#include <iostream>
#include <cuda_runtime.h>

class Particles {
	// contient les SoA sur gpu
public:
	Particles() ; 
//	Particles(int); 
	~Particles(); 
	void allocateParticles(int) ; // à refaire puisqu'on veut un solide custom

	int nParticles ; 

	float *d_x, *d_y, *d_z ; 
	float *d_vx, *d_vy, *d_vz ; 
	float *d_mass, *d_volume, *d_density ;
	float *d_sig_xx, *d_sig_yy, *d_sig_zz, *d_sig_xy, *d_sig_xz, *d_sig_yz ; // symmetric stress tensor, 6 values per particle
        float *d_eps_xx, *d_eps_yy, *d_eps_zz, *d_eps_xy, *d_eps_xz, *d_eps_yz ; // symmetric strain tensor, 6 values per particle
	float *d_weights ; // interpolation values. Be careful : size depends on Interpolation::Type...

	int* d_phase ; 


};

class Body {
	// a termes : va contenir plusieurs solides. Pour le moment : un seul solude donc classe semble inutile. 
public:
	Body() ; 
	~Body();
	void addBody(int ) ; 

	int nBodies ; // nombre de corps differents ; 
	Particles  particles ; 
		
};

#endif
