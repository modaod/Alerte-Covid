#include "Interface.h"
#include <iomanip>
#include "Graph.h"

bool grapheCree = false;

Interface::~Interface() {
	//do nothing
}

/**
* Affiche le menu principal
*/
void Interface::afficherInterface()
{
	bool fin = false;
	string input;
	char option;
	while (!fin)
	{
		system("CLS");
		std::cout << '\n'<< std:: setw(50) <<" "  <<"-Menu global-\n"  << std::endl;
		std::cout << "Selectionnez une des options suivantes : \n" << std::endl;
		std::cout << "(a) Lancer tracage COVID" << std::endl
			<< "(b) Quitter" << std::endl;

		cin >> input;
		if (input.size() == 1)
		{
			option = input.at(0);

			switch (option)
			{
			case 'a':
				afficherInterfaceCovid();
				break;
			case 'b':
				fin = true;
				break;
			default:
				std::cout << "\n Veuillez choisir une option valide.\n" << std::endl;
				system("pause");
			}
		}
		else {
			std::cout << "\n Veuillez choisir une option valide.\n" << std::endl;
			system("pause");
		}
		
	}
 
}

/**
* Affiche le menu de l'application Alerte COVID
*/
void Interface::afficherInterfaceCovid()
{
	bool fin = false;
	string input;
	char option;

	system("CLS");

	 std::cout << '\n' << std::setw(50) << " " << "-Menu COVID19-\n" << std::endl;
		std::cout << "Selectionnez une des options suivantes : \n" << std::endl;
		std::cout << "(a) Creer le graph d'exposition" << std::endl
			<< "(b) Afficher le graphe d'exposition" << std::endl
			<< "(c) Verifier si une personne est exposee au COVID19" << std::endl
			<< "(d) Verifier si deux personnes ont eu un contact rapproche" << std::endl
			<< "(e) Quitter" << std::endl;

		cin >> input;
		if (input.size() == 1)
		{
			option = input.at(0);

			switch (option)
			{
			case 'a':
			{
				creationGraphreExposition();
				system("pause");
				break;
			}
			case 'b':

				AffichageGrapheExposition();
				system("pause");
				break;

			case 'c':
			{

				envoyerNotification('c');
				system("pause");
				break;
			}
			case 'd':
			{

				envoyerNotification('d');
				system("pause");
				break;
			}
			case 'e':
				fin = true;
				std::cout << "retour au menu global" << std::endl;
				system("pause");
				break;

			default:
				std::cout << "\nSaisie invalide.\n" << std::endl;
				system("pause");
				break;
			}

		}
		else {
			std::cout << "\n Veuillez choisir une option valide.\n" << std::endl;
			system("pause");
		}
		if (fin == false)
			afficherInterfaceCovid();
		
}


void Interface::creationGraphreExposition()
{
	std::cout << "Creation du graphe\n " << std::endl;

	std::cout << "\nSaisir le nom du fichier .txt d'individus a analyser : ";
	std::string fichierIndividusTxt;
	std::cin >> fichierIndividusTxt;

	std::cout << "Saisir le nom du fichier .txt des contacts entres les individus : ";
	std::string fichierContactsTxt;
	std::cin >> fichierContactsTxt;
	
	if (graphe_.fichierChargees(fichierIndividusTxt, fichierContactsTxt))
	{
		graphe_.creerGrapheExposition(fichierIndividusTxt, fichierContactsTxt);
		std::cout << "\nLe graph est bien cree. Selectionnez l'option (b) pour l'afficher\n" << std::endl;
		grapheCree = true;
		
	}
	else
		std::cout << "\nProbleme survenu\n" << std::endl;

	
}
void Interface::AffichageGrapheExposition()
{
	if (grapheCree == true)
	{
		std::cout << "Affichage du graphe\n " << std::endl;
		graphe_.afficherGrapheExposition();
	}
	else
		std::cout << "Veuillez choisir l'option (a) avant de continuer s'il vous plait\n" << std::endl;
}
void Interface::envoyerNotification(const char& option)
{
	if (grapheCree == true)
	{
		if (option == 'c')
		{
			std::cout << "\nSaisir le nom de la personne a verifier : ";
			std::string nom;
			std::cin >> nom;
			// std::cout << "Verification en cours\n " << std::endl;
			graphe_.verifierExposition(nom);
		}
		else
		{
			std::string nom1, nom2;
			std::cout << "\nSaisir le nom de la premiere personne : ";
			std::cin >> nom1;
			std::cout << "\nSaisir le nom de la deuxieme personne : ";
			std::cin >> nom2;
			// std::cout << "Verification en cours\n " << std::endl;
			graphe_.verifierExposition(nom1, nom2);
		}
	}
	else 
		std::cout << "Veuillez choisir l'option (a) avant de continuer s'il vous plait\n" << std::endl;
}

