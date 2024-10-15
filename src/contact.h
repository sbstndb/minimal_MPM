#ifndef CONTACT_H
#define CONTACT_H

class Contact {
public:
	enum class Type {
		Standard
	};
	Type type = Contact::Type::Standard ; 
};

#endif
