
#include <iostream>
#include "solver.h"

Solver::Solver(){
       std::cout << "Solver Constructor" << std::endl ;
	interpolation.setType(Interpolation::Type::Linear)  ; 
};


Solver::~Solver(){
	std::cout << "Solver Destructor" << std::endl ;
}; 




