#include <iostream>
#include "math.h"


// Kernel CUDA simple
__global__ void algoKernel() {
    printf("Exécution d'un algorithme sur le GPU.\n");
}

// Fonction hôte
void algoFunction() {
    algoKernel<<<1, 1>>>();
    cudaDeviceSynchronize();
}

// Fonction appelée depuis main.cpp
void cudaFunction() {
    mathFunction();
    algoFunction();
}

