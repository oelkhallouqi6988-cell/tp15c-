
#include <iostream>
#include <string>

using namespace std;

// 1. Classe Noeud
class Noeud
{
public:
    int cle;
    string valeur;
    Noeud* suivant;

    Noeud(int c, string v)
    {
        cle = c;
        valeur = v;
        suivant = nullptr;
    }
};

// 2. Classe TableHachage
class TableHachage
{
private:
    static const int TAILLE = 10;
    Noeud* table[TAILLE];

    // Fonction de hachage
    int hachage(int cle)
    {
        return cle % TAILLE;
    }

public:

    // Constructeur
    TableHachage()
    {
        for (int i = 0; i < TAILLE; i++)
        {
            table[i] = nullptr;
        }
    }

    // Inserer un element
    void inserer(int cle, string valeur)
    {
        int index = hachage(cle);

        Noeud* temp = table[index];

        // Verifier si la cle existe deja
        while (temp != nullptr)
        {
            if (temp->cle == cle)
            {
                temp->valeur = valeur;
                cout << "Valeur mise a jour !" << endl;
                return;
            }

            temp = temp->suivant;
        }

        // Creer un nouveau noeud
        Noeud* nouveau = new Noeud(cle, valeur);

        // Ajouter au debut de la liste
        nouveau->suivant = table[index];
        table[index] = nouveau;

        cout << "Element insere avec succes !" << endl;
    }

    // Rechercher une cle
    string rechercher(int cle)
    {
        int index = hachage(cle);

        Noeud* temp = table[index];

        while (temp != nullptr)
        {
            if (temp->cle == cle)
            {
                return temp->valeur;
            }

            temp = temp->suivant;
        }

        return "Cle introuvable !";
    }

    // Supprimer une cle
    void supprimer(int cle)
    {
        int index = hachage(cle);

        Noeud* temp = table[index];
        Noeud* precedent = nullptr;

        while (temp != nullptr)
        {
            if (temp->cle == cle)
            {
                if (precedent == nullptr)
                {
                    table[index] = temp->suivant;
                }
                else
                {
                    precedent->suivant = temp->suivant;
                }

                delete temp;

                cout << "Element supprime !" << endl;
                return;
            }

            precedent = temp;
            temp = temp->suivant;
        }

        cout << "Cle introuvable !" << endl;
    }

    // Afficher toute la table
    void afficher()
    {
        cout << "\n===== TABLE DE HACHAGE =====" << endl;

        for (int i = 0; i < TAILLE; i++)
        {
            cout << "Case " << i << " : ";

            Noeud* temp = table[i];

            while (temp != nullptr)
            {
                cout << "[" << temp->cle
                     << " : " << temp->valeur << "] -> ";

                temp = temp->suivant;
            }

            cout << "NULL" << endl;
        }
    }

    // Destructeur
    ~TableHachage()
    {
        for (int i = 0; i < TAILLE; i++)
        {
            Noeud* temp = table[i];

            while (temp != nullptr)
            {
                Noeud* aSupprimer = temp;
                temp = temp->suivant;

                delete aSupprimer;
            }
        }
    }
};

// 3. Programme principal
int main()
{
    TableHachage t;

    // Insertion
    cout << "=== INSERTION ===" << endl;

    t.inserer(10, "Ali");
    t.inserer(20, "Sara");
    t.inserer(15, "Ahmed");
    t.inserer(25, "Youssef");
    t.inserer(7, "Fatima");

    // Affichage
    t.afficher();

    // Recherche
    cout << "\n=== RECHERCHE ===" << endl;

    cout << "Cle 20 : " << t.rechercher(20) << endl;
    cout << "Cle 15 : " << t.rechercher(15) << endl;
    cout << "Cle 50 : " << t.rechercher(50) << endl;

    // Suppression
    cout << "\n=== SUPPRESSION ===" << endl;

    t.supprimer(20);

    // Affichage apres suppression
    t.afficher();

    return 0;
}
