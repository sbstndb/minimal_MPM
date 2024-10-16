#include <iostream>
#include "interpolation.h"

Interpolation::Interpolation(){} ; 
Interpolation::~Interpolation(){};


void Interpolation::setType(Interpolation::Type type_){
	Interpolation::type = type_ ; 
	std::cout << "Set to interpolation type : " << (int)type_ << std::endl ; 
}

