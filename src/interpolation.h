#ifndef INTERPOLATION_H
#define INTERPOLATION_H

class Interpolation {
public:
	enum class Type {
		Linear,
		Gimp,
		Cpdi,
		QuadSpline,
		CubicSpline
	};
	Type type = Interpolation::Type::Linear ; 
};

#endif
