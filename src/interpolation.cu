#include "interpolation.h"
#include <iostream>
/**
        // define shape functions
        float Interp(float, float, float, float, float, float) ; // switch case in Type
        //
        float LinearInterp(float, float, float, float, float, float) ;
        float GimpInterp(float, float, float, float, float, float) ;
        float CpdiInterp(float, float, float, float, float, float) ;
        float QuadSplineInterp(float, float, float, float, float, float) ;
        float CubicSplineInterp(float, float, float, float, float, float) ;
**/



__device__ float linearInterp(float xp, float yp, float zp, float xn, float yn, float zn, float h){
	// without if condition, its a low level function
	float xd = abs(xp - xn) ; 
	float yd = abs(yp - yn) ;
	float zd = abs(zp - zn) ; 

	float w = xd * yd * zd / h ; 
	return w ; 
};



__global__ void weightInterpKernel(
		float *d_xp, float *d_yp, float *d_zp,
		float *d_xn, float *d_yn, float *d_zn,
		int *d_node_x, int * d_node_y, int * d_node_z,
		float *d_weights, 
		int nParticles, 
		int nx, int ny, int nz, float h){
	// Be careful : only with linear shape function because of d weights
	int idx = blockIdx.x * blockDim.x + threadIdx.x ; 
	if (idx >= nParticles) return ; 
	// now we want to compute 8 weights per particles, stored in d_weigths
	
	// particle positions
	float xp = d_xp[idx] ; 
	float yp = d_yp[idx] ; 
	float zp = d_zp[idx] ; 

	// grid indexes
	int i0 = floorf(xp/h); 
	int j0 = floorf(yp/h);
	int k0 = floorf(zp/h);

	// future : verifier que les indices sont dans les bonnes limites, 
	// avec min(max(i0, 0), nx-2) par ex
	//

	int index_node;
	int index_weight= 0 ; 
	float xn, yn, zn ; 
	float weight;

	for (int i = i0 ; i < i0 + 2 ; i++){
		for (int j = j0 ; j < j0 + 2 ; j++){
			for (int k = k0 ; k < k0 + 2 ; k++){
			        index_node = k * (nx*ny) + j*nx + i;
			        xn = d_xn[index_node];
			        yn = d_yn[index_node] ;
			        zn = d_zn[index_node] ;
			        weight = linearInterp(xp, yp, zp, xn, yn, zn, h);
				d_weights[index_weight] = weight ; 
				index_weight++;
			}
		}
	}

}

void Interpolation::weightInterp(
                float *d_xp, float *d_yp, float *d_zp,
                float *d_xn, float *d_yn, float *d_zn,
		int *d_node_x, int* d_node_y, int *d_node_z ,
                float *d_weights,
                int nParticles,
                int nx, int ny, int nz, float h){

        int threadsPerBlocks = 256 ;
        int blocksPerGrid = (nParticles + threadsPerBlocks -1)/threadsPerBlocks ;

        weightInterpKernel<<<threadsPerBlocks, blocksPerGrid>>>(
                        d_xp, d_yp, d_zp,
                        d_xn, d_yn, d_zn,
			d_node_x, d_node_y, d_node_z,
                        d_weights,
                        nParticles,
                        nx, ny, nz, h) ;

        cudaDeviceSynchronize() ;
	std::cout << "Weight Interpolation" << std::endl ; 
};


__global__ void P2GKernel(float *fp, float *fi, float *weights, int nParticles){
        // Be careful : only with linear shape function because of d weights
        int idx = blockIdx.x * blockDim.x + threadIdx.x ;
        if (idx >= nParticles) return ;

}

__global__ void G2PKernel(float *fp, float *fi, float *weights, int nParticles){
        // Be careful : only with linear shape function because of d weights
        int idx = blockIdx.x * blockDim.x + threadIdx.x ;
        if (idx >= nParticles) return ;

}




void P2G(float *fp, float * fi , float * weights, int nParticles){
	// be careful : 
	// TODO : add type of interpolation , spline etc
        int threadsPerBlocks = 256 ;
        int blocksPerGrid = (nParticles + threadsPerBlocks -1)/threadsPerBlocks ;
	P2GKernel<<<threadsPerBlocks, blocksPerGrid>>>(fp, fi, weights, nParticles);

}

void G2P(float *fp, float *fi, float* weights, int nParticles){
        int threadsPerBlocks = 256 ;
        // TODO : add type of interpolation , spline etc	
        int blocksPerGrid = (nParticles + threadsPerBlocks -1)/threadsPerBlocks ;
	G2PKernel<<<threadsPerBlocks, blocksPerGrid>>>(fp, fi, weights, nParticles) ; 

}




