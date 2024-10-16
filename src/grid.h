#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <cuda_runtime.h>



class Grid {
public:
	Grid() ; 
	~Grid() ; 

	void addGrid(int, int, int, float) ; 
	void allocateGrid(int ) ; 
 	void initializeGrid();
	//void initializeGridKernel(float*, float*, float*, int, int, int, float);


	int nx, ny, nz;
	int n; 
	float h; // hx = hy = hz for now
	float lx, ly, lz ; 


	// cuda arrays 
	// In reality we can use limited amount of arrays because you dont need them at th same time
	float *d_x, *d_y, *d_z ; 
	float *d_vx, *d_vy, *d_vz;
	float *d_px, *d_py, *d_pz;
	float *d_mass;

};













#endif


