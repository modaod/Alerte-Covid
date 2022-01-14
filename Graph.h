#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
//#include <vector>
#include "Contacts.h"

constexpr auto DEUX_METRE = 2.0;

class Graph {
public:
	Graph() = default;
	~Graph();

	void creerGrapheExposition(const string& Fichier1, const string& Fichier2);
	void afficherGrapheExposition();
	void identifierExposition(const string&, const string&);
	void NotifierExposition(const string&);
	ostream& afficherContacts(ostream& os) const;
	ostream& afficherPersonnes(ostream& os) const;
	bool fichierChargees(const string& nomFichier1, const string& nomFichier2);
	Graph& operator+=(const Personne& personne);
	Graph& operator+=(const Contacts& contacts);
	int indicePersonne(const string& nom);
	//vector<Personne> getListePersonnes() const;

private:
	void afficherGraph(ostream& os) const;
	bool exposition(const string&);
	bool exposition(const string&, const string&);
	bool chargerContacts(const string& nomFichier);
	bool chargerPersonnes(const string& nomFichier);

	set<Personne*> listePersonnes_;
	set<Contacts*> listeContacts_;

};

#endif	//GRAPH_H