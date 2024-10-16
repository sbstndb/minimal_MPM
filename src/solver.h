#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include "temporalScheme.h"
#include "interpolation.h"
#include "contact.h"


class Solver {
public:
	Solver() ; 
	~Solver() ; 


//	TemporalScheme temporalScheme(TemporalScheme::Type::Explicit) ; 
	TemporalScheme temporalScheme ; 
	Interpolation interpolation ; 
	ExplicitScheme explicitScheme ; 
	Contact contact ; 

/**
	void computeInterpolation3D(){ // arguments à reflechir
				     // float x1, x2, x3, y1, y2, y3
		switch (interpolation){
			case Interpolation::Linear:
				// compute with linear
				break ; 
			case Interpolation::QuadSpline:
				// compute with quadspline
				break ;
			default : 
				std::cout << "Error : Interpolation non geree pour le moment" << std::cout ; 
				break ; 
		}
	}

**/

private:

};


#endif
