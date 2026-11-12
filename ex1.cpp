
#include <iostream>
using namespace std;

// 1. Classe Noeud
class Noeud
{
public:
    int valeur;
    Noeud* suivant;

    // Constructeur
    Noeud(int v)
    {
        valeur = v;
        suivant = nullptr;
    }
};

// 2. Classe ListeChainee
class ListeChainee
{
private:
    Noeud* tete;
    int compteur;

public:
    // Constructeur
    ListeChainee()
    {
        tete = nullptr;
        compteur = 0;
    }

    // Ajouter un element au debut
    void ajouterDebut(int valeur)
    {
        Noeud* nouveau = new Noeud(valeur);

        nouveau->suivant = tete;
        tete = nouveau;

        compteur++;
    }

    // Ajouter un element a la fin
    void ajouterFin(int valeur)
    {
        Noeud* nouveau = new Noeud(valeur);

        if (tete == nullptr)
        {
            tete = nouveau;
        }
        else
        {
            Noeud* temp = tete;

            while (temp->suivant != nullptr)
            {
                temp = temp->suivant;
            }

            temp->suivant = nouveau;
        }

        compteur++;
    }

    // Supprimer un element
    void supprimer(int valeur)
    {
        if (tete == nullptr)
        {
            cout << "La liste est vide !" << endl;
            return;
        }

        // Si l'element a supprimer est le premier
        if (tete->valeur == valeur)
        {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;

            compteur--;
            cout << "Element supprime." << endl;
            return;
        }

        Noeud* temp = tete;

        while (temp->suivant != nullptr &&
               temp->suivant->valeur != valeur)
        {
            temp = temp->suivant;
        }

        if (temp->suivant == nullptr)
        {
            cout << "Element introuvable !" << endl;
            return;
        }

        Noeud* aSupprimer = temp->suivant;
        temp->suivant = aSupprimer->suivant;

        delete aSupprimer;
        compteur--;

        cout << "Element supprime." << endl;
    }

    // Afficher la liste
    void afficher()
    {
        Noeud* temp = tete;

        cout << "Liste : ";

        while (temp != nullptr)
        {
            cout << temp->valeur << " -> ";
            temp = temp->suivant;
        }

        cout << "NULL" << endl;
    }

    // Retourner la taille de la liste
    int taille()
    {
        return compteur;
    }

    // 3. Iterateur personnalise
    class Iterateur
    {
    private:
        Noeud* courant;

    public:
        Iterateur(Noeud* n)
        {
            courant = n;
        }

        bool operator!=(const Iterateur& autre) const
        {
            return courant != autre.courant;
        }

        int operator*() const
        {
            return courant->valeur;
        }

        Iterateur& operator++()
        {
            courant = courant->suivant;
            return *this;
        }
    };

    // Debut de l'iteration
    Iterateur begin()
    {
        return Iterateur(tete);
    }

    // Fin de l'iteration
    Iterateur end()
    {
        return Iterateur(nullptr);
    }

    // 4. Destructeur
    ~ListeChainee()
    {
        Noeud* temp;

        while (tete != nullptr)
        {
            temp = tete;
            tete = tete->suivant;
            delete temp;
        }

        cout << "Memoire liberee !" << endl;
    }
};

// 5. Programme principal
int main()
{
    ListeChainee liste;

    // Ajouter au debut
    liste.ajouterDebut(10);
    liste.ajouterDebut(20);

    // Ajouter a la fin
    liste.ajouterFin(30);
    liste.ajouterFin(40);

    cout << "=== Liste initiale ===" << endl;
    liste.afficher();

    // Afficher la taille
    cout << "Taille : " << liste.taille() << endl;

    // Supprimer un element
    cout << "\n=== Suppression ===" << endl;
    liste.supprimer(20);
    liste.afficher();

    // Utilisation de l'iterateur
    cout << "\n=== Parcours avec iterateur ===" << endl;

    for (ListeChainee::Iterateur it = liste.begin();
         it != liste.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    cout << "\nTaille finale : " << liste.taille() << endl;

    return 0;
}
