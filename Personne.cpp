#include "Personne.h"

Personne::Personne(std::string nom, bool estInfecte) : nom_(nom), estInfecte_(estInfecte)
{
}

string Personne::getNom() const { return nom_; }

int Personne::estInfecte() const { return estInfecte_; }

void Personne::setNom(std::string nom) { nom_ = nom; }

void Personne::setEstinfecte(bool estInfecte) { estInfecte_ = estInfecte; }
