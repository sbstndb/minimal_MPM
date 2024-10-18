#ifndef INTERPOLATION_H
#define INTERPOLATION_H

class Interpolation {
public:

	Interpolation() ; 
	~Interpolation() ; 

	enum class Type {
		Linear,
		Gimp,
		Cpdi,
		QuadSpline,
		CubicSpline
	};

	Type type = Interpolation::Type::Linear ; 
	void setType(Type) ; 


	// define shape functions 
	float Interp(float, float, float, float, float, float) ; // switch case in Type
								 //
	void weightInterp(float *d_xp, float *d_yp, float *_zp,
                float *d_xi, float *d_yi, float *d_zi,
		int *d_node_x, int *d_node_y, int* d_node_z,
                float *d_weights,
                int nParticles,
                int nx, int ny, int nz, float h);								
	//
	// define particle grid transfert funtions
	// fpx : field particle x 
//	void P2G(float* fpx, float* fpy, float* fpz, float* fnx, float* fny, float* fnz) ; 
//	void G2P(float* fpx, float* fpy, float* fpz, float* fnx, float* fny, float* fnz) ; 

	void P2G(float * fp, float * fi, float * weights, int nParticles) ; 
        void G2P(float * fp, float * fi, float * weights, int nParticles) ;
	

};

#endif
