#pragma once
#ifndef CONTACTS_H
#define CONTACTS_H

#include "Personne.h"

class Contacts {
public:
	Contacts(Personne, Personne, double);
	~Contacts();
	Personne getFrom() const;
	Personne getTo() const;
	double getDistance() const;

private:
	Personne from_;
	Personne to_;
	double distance_;
};

#endif // CONTACTS_H