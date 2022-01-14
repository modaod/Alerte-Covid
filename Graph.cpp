#include "Graph.h"

Graph::~Graph() {
    for (auto it = listePersonnes_.begin(); it != listePersonnes_.end(); it++) {
        delete* it;
    }

    for (auto it = listeContacts_.begin(); it != listeContacts_.end(); it++) {
        delete* it;
    }
}

/*
@param fichier1: nom du fichier des Individus
@param fichier2: nom du fichier de contacts
*/
void Graph::creerGrapheExposition(const string& fichier1, const string& fichier2) {
    

    if (fichierChargees(fichier1,fichier2))
        std::cout << "Lecture des fichiers terminee \n\n";
    else
        std::cout << "Les fichiers n'ont pas pu etre charges.\n";
}

void Graph::afficherGrapheExposition() {
    afficherGraph(std::cout);
}

void Graph::identifierExposition(const string& nom1, const string& nom2) {
    bool estExpose = exposition(nom1, nom2);
    if (estExpose)
        cout << nom1 << " a ete expose(e) par " << nom2 << endl;
    else
        cout << "Aucune exposition detectee " << endl;
}

void Graph::NotifierExposition(const string& nom) {
    bool estExpose = exposition(nom);
    if (estExpose)
        cout << "Vous avez ete expose au cours des 14 derniers jours. \n";
    else
        cout << "Aucune exposition detectee. \n";
}

Graph& Graph::operator+=(const Personne& personne) {
    listePersonnes_.insert(new Personne(personne));
    return *this;
}

Graph& Graph::operator+=(const Contacts& contact) {
    listeContacts_.insert(new Contacts(contact));
    return *this;
}

bool Graph::chargerPersonnes(const string& nomFichier) {
    std::ifstream fichier(nomFichier);

    if (fichier)
    {
        listePersonnes_.clear();
        string ligne1, ligne2;
        string nom;
        int indice;

        while (getline(fichier, ligne1, ','))
        {
            std::istringstream stream(ligne1);
            stream >> nom;

            getline(fichier, ligne2);
            std::istringstream stream2(ligne2);
            stream2 >> indice;

            Personne personne(nom, indice);
            (*this) += personne;
        }
        return true;
    }
    std::cerr << "Le fichier " << nomFichier
        << " n'existe pas. Assurez vous de le mettre au bon endroit.\n";
    return false;
}

bool Graph::chargerContacts(const string& nomFichier) {
    std::ifstream fichier(nomFichier);

    if (fichier)
    {
        listeContacts_.clear();
        string ligne;

        while (getline(fichier, ligne))
        {
            string nom1, nom2;
            double distance;
            std::istringstream stream(ligne);

            stream >> nom1 >> distance >> nom2;
            int indice1 = indicePersonne(nom1);
            int indice2 = indicePersonne(nom2);
            Personne pers1(nom1, indice1);
            Personne pers2(nom2, indice2);
            Contacts contact(pers1, pers2, distance);
            (*this) += contact;
        }
        return true;
    }
    std::cerr << "Le fichier " << nomFichier
        << " n'existe pas. Assurez vous de le mettre au bon endroit.\n";
    return false;
}

int Graph::indicePersonne(const string& nom) {
    for (auto it = listePersonnes_.begin(); it != listePersonnes_.end(); it++) {
        if ((*it)->getNom() == nom)
            return (*it)->estInfecte();
    }
    return 0;
}

ostream& Graph::afficherContacts(ostream& os) const {
    for (auto it = listeContacts_.begin(); it != listeContacts_.end(); it++) {
        os << (*it)->getFrom().getNom() << "(" << (*it)->getFrom().estInfecte()
            << ")" << " " << (*it)->getDistance() << " "
            << (*it)->getTo().getNom() << "(" << (*it)->getTo().estInfecte()
            << ")" << endl;
    }
    return os;
}


ostream& Graph::afficherPersonnes(ostream& os) const {
    for (auto& v : listePersonnes_)
        os << v->getNom() << " " << v->estInfecte() << endl;
    return os;
}

bool Graph::fichierChargees(const string& nomFichier1, const string& nomFichier2)
{
    bool chargees = false;
    if (chargerPersonnes(nomFichier1) && chargerContacts(nomFichier2))
          chargees = true;
    return chargees;
}

void Graph::afficherGraph(ostream& os) const {
    for (auto& v : listeContacts_)
        os << v->getFrom().getNom() << " " << v->getTo().getNom()
        << " " << "(" << v->getDistance() << ")" << endl;
}

bool Graph::exposition(const string& nom1, const string& nom2) {
    for (auto& v : listeContacts_) {
        if (v->getFrom().getNom() == nom1 && v->getTo().getNom() == nom2
            && v->getDistance() <= DEUX_METRE)
            return true;
        else if (v->getFrom().getNom() == nom2 && v->getTo().getNom() == nom1
            && v->getDistance() <= DEUX_METRE)
            return true;
    }
    return false;
}

bool Graph::exposition(const string& nom) {
    for (auto& v : listeContacts_) {
        if (v->getFrom().getNom() == nom || v->getTo().getNom() == nom
            && v->getDistance() <= DEUX_METRE)
            return true;
    }
    return false;
}