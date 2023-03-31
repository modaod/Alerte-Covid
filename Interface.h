#pragma once
#include"Graph.h"


class Interface {

public:
	Interface() = default;
	~Interface();
	void afficherInterface();
	void afficherInterfaceCovid();

private:
	Graph graphe_;
	void creationGraphreExposition();
	void AffichageGrapheExposition();
	void envoyerNotification(const char& option);


};