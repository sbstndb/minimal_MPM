#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <cuda_runtime.h>



class Grid {
public:
	Grid() ; 
	~Grid() ; 

	void addGrid(float, float, float, float) ; 
	void allocateGrid(int ) ; 

	void 

	int nx, nt, nz;
	float h; // hx = hy = hz for now

	// cuda arrays 
	// In reality we can use limited amount of arrays because you dont need them at th same time
	float *d_x, *d_y, *d_z ; 
	float *d_vx, *d_vy, *d_vz;
	float *d_px, *d_py, *d_pz;
	float *d_mass;

};













#endif


