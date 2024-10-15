#include <iostream>
#include "math.h"

// Kernel CUDA simple
__global__ void mathKernel() {
    printf("Calculs mathématiques sur le GPU.\n");
}

// Fonction hôte
void mathFunction() {
    mathKernel<<<1, 1>>>();
    cudaDeviceSynchronize();
}

