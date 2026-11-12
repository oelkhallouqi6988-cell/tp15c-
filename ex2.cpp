
#include <iostream>
#include <stdexcept>

using namespace std;

// 1. Classe Noeud
class Noeud
{
public:
    int valeur;
    Noeud* suivant;

    Noeud(int v)
    {
        valeur = v;
        suivant = nullptr;
    }
};

// 2. Classe File
class File
{
private:
    Noeud* debut;
    Noeud* fin;

public:

    // Constructeur
    File()
    {
        debut = nullptr;
        fin = nullptr;
    }

    // Verifier si la file est vide
    bool estVide()
    {
        return debut == nullptr;
    }

    // Verifier si la file est pleine
    bool estPleine()
    {
        // Avec une liste chainee dynamique,
        // la file est pleine si la memoire est insuffisante.
        return false;
    }

    // Ajouter un element dans la file
    void enfiler(int valeur)
    {
        Noeud* nouveau = new Noeud(valeur);

        if (estVide())
        {
            debut = nouveau;
            fin = nouveau;
        }
        else
        {
            fin->suivant = nouveau;
            fin = nouveau;
        }

        cout << "Element ajoute : " << valeur << endl;
    }

    // Retirer un element de la file
    int defiler()
    {
        if (estVide())
        {
            throw runtime_error("Erreur : la file est vide !");
        }

        Noeud* temp = debut;
        int valeur = temp->valeur;

        debut = debut->suivant;

        if (debut == nullptr)
        {
            fin = nullptr;
        }

        delete temp;

        return valeur;
    }

    // Afficher les elements de la file
    void afficher()
    {
        if (estVide())
        {
            cout << "La file est vide !" << endl;
            return;
        }

        Noeud* temp = debut;

        cout << "File : ";

        while (temp != nullptr)
        {
            cout << temp->valeur << " <- ";
            temp = temp->suivant;
        }

        cout << "FIN" << endl;
    }

    // Destructeur
    ~File()
    {
        while (!estVide())
        {
            Noeud* temp = debut;
            debut = debut->suivant;
            delete temp;
        }

        fin = nullptr;
    }
};

// 3. Programme principal
int main()
{
    File f;
    int choix;
    int valeur;

    do
    {
        cout << "\n===== MENU FILE D'ATTENTE =====" << endl;
        cout << "1. Enfiler un element" << endl;
        cout << "2. Defiler un element" << endl;
        cout << "3. Afficher la file" << endl;
        cout << "4. Verifier si la file est vide" << endl;
        cout << "5. Verifier si la file est pleine" << endl;
        cout << "0. Quitter" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        switch (choix)
        {
            case 1:
                cout << "Entrer une valeur : ";
                cin >> valeur;
                f.enfiler(valeur);
                break;

            case 2:
                try
                {
                    valeur = f.defiler();
                    cout << "Element retire : " << valeur << endl;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                }
                break;

            case 3:
                f.afficher();
                break;

            case 4:
                if (f.estVide())
                    cout << "La file est vide." << endl;
                else
                    cout << "La file n'est pas vide." << endl;
                break;

            case 5:
                if (f.estPleine())
                    cout << "La file est pleine." << endl;
                else
                    cout << "La file n'est pas pleine." << endl;
                break;

            case 0:
                cout << "Fin du programme." << endl;
                break;

            default:
                cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    return 0;
}
