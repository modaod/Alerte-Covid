#pragma once
#ifndef PERSONNE_H
#define PERSONNE_H

#include<string>

using namespace std;

class Personne {
public:
	Personne(std::string nom, bool estInfecte);
	std::string getNom() const;
	int estInfecte() const;
	void setNom(std::string Nom);
	void setEstinfecte(bool estInfecte);

private:

	std::string nom_;
	int estInfecte_;

};

#endif	//PERSONNE_H