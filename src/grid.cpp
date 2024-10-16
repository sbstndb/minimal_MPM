#include <iostream>
#include "grid.h"

Grid::Grid(){} ; 
Grid::~Grid(){
	std::cout << "Desctror grid " << std::endl ; 
        cudaFree((void*)d_x);
        cudaFree((void*)d_y);
        cudaFree((void*)d_z);

        cudaFree((void*)d_vx);
        cudaFree((void*)d_vy);
        cudaFree((void*)d_vz);

        cudaFree((void*)d_px);
        cudaFree((void*)d_py);
        cudaFree((void*)d_pz);

        cudaFree((void*)d_mass);
};

void Grid::addGrid(float dx, float dy, float dz, float h){

};


void Grid::allocateGrid(int nNodes){
        std::cout << "Allocate grid " << std::endl ;

        cudaMalloc((void**)&d_x, nNodes * sizeof(float)) ;
        cudaMalloc((void**)&d_y, nNodes * sizeof(float)) ;
        cudaMalloc((void**)&d_z, nNodes * sizeof(float)) ;

        cudaMalloc((void**)&d_vx, nNodes * sizeof(float)) ;
        cudaMalloc((void**)&d_vy, nNodes * sizeof(float)) ;
        cudaMalloc((void**)&d_vz, nNodes * sizeof(float)) ;

        cudaMalloc((void**)&d_px, nNodes * sizeof(float)) ;
        cudaMalloc((void**)&d_py, nNodes * sizeof(float)) ;
        cudaMalloc((void**)&d_pz, nNodes * sizeof(float)) ;

        cudaMalloc((void**)&d_mass, nNodes * sizeof(float)) ;

};



