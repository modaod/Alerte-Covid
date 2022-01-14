#include "Contacts.h"

Contacts::Contacts(Personne personne1, Personne personne2, double distance) :
	from_(personne1), to_(personne2), distance_(distance)
{}

Contacts::~Contacts() {
	//delete from_;
	//delete to_;
}

Personne Contacts::getFrom() const { return from_; }

Personne Contacts::getTo() const { return to_; }

double Contacts::getDistance() const { return distance_; }



