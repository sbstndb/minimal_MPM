#include "grid.h"
#include <iostream>


__global__ void initializeGridKernel(float* d_x, float* d_y, float *d_z, int nx, int ny, int nz, float h){
	int i = blockIdx.x * blockDim.x + threadIdx.x ; 
        int j = blockIdx.y * blockDim.y + threadIdx.y ;
        int k = blockIdx.z * blockDim.z + threadIdx.z ;
	
	if (i < nx && j < ny && k < nz){
		int index = k * (nx*ny) + j*nx + i ;
		d_x[index] = static_cast<float>(i*h) ; 
		d_y[index] = static_cast<float>(j*h) ;
		d_z[index] = static_cast<float>(k*h);
	}

}

void Grid::initializeGrid(){
	// definition des blocs
	dim3 threadsPerBlocks(8,8,8) ; 
	dim3 blockPerGrid(
		(nx + threadsPerBlocks.x - 1)  / threadsPerBlocks.x ,
                (ny + threadsPerBlocks.y - 1)  / threadsPerBlocks.y ,
                (nz + threadsPerBlocks.z - 1)  / threadsPerBlocks.z 
		
	);
        initializeGridKernel<<<threadsPerBlocks, blockPerGrid>>>(d_x, d_y, d_z, nx, ny, nz, h) ;
        cudaDeviceSynchronize();
	std::cout << "grid initialized" << std::endl ; 
};

