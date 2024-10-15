#ifndef TEMPORALSCHEME_H
#define TEMPORALSCHEME_H

class TemporalScheme {
public:
	enum class Type {
		Explicit,
		Implicit
	};

	Type type = TemporalScheme::Type::Explicit; 
};


class ExplicitScheme {
public:
	enum class Type {
		Usf,
                Usl,
		Musl,
	};
	Type type = ExplicitScheme::Type::Usf; 
};

#endif
