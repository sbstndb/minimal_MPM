#include <iostream>
#include "algorithms.h"
#include "utils.h"

int main(){
	std::cout << "Appel de fonction cuda" << std::endl ; 
	cudaFunction() ; 
	std::cout << "Terminé" << std::endl ; 
	return 0 ; 
}
