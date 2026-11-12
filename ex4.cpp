#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// 1. Classe Pile generique
template <typename T>
class Pile
{
private:
    vector<T> elements;

public:

    // Empiler un element
    void empiler(T element)
    {
        elements.push_back(element);
        cout << "Element empile avec succes !" << endl;
    }

    // Depiler un element
    T depiler()
    {
        if (estVide())
        {
            throw runtime_error("Erreur : la pile est vide !");
        }

        T element = elements.back();
        elements.pop_back();

        return element;
    }

    // Retourner le sommet de la pile
    T sommet() const
    {
        if (estVide())
        {
            throw runtime_error("Erreur : la pile est vide !");
        }

        return elements.back();
    }

    // Verifier si la pile est vide
    bool estVide() const
    {
        return elements.empty();
    }

    // Inverser la pile
    void inverser()
    {
        int debut = 0;
        int fin = elements.size() - 1;

        while (debut < fin)
        {
            T temp = elements[debut];
            elements[debut] = elements[fin];
            elements[fin] = temp;

            debut++;
            fin--;
        }
    }

    // Afficher la pile
    void afficher() const
    {
        if (estVide())
        {
            cout << "La pile est vide !" << endl;
            return;
        }

        cout << "Pile (base -> sommet) : ";

        for (int i = 0; i < elements.size(); i++)
        {
            cout << elements[i] << " ";
        }

        cout << endl;
    }
};

// 2. Programme principal
int main()
{
    // Test avec int
    cout << "===== PILE D'ENTIERS =====" << endl;

    Pile<int> p1;

    p1.empiler(10);
    p1.empiler(20);
    p1.empiler(30);

    p1.afficher();

    cout << "Sommet : " << p1.sommet() << endl;

    cout << "Element depile : " << p1.depiler() << endl;

    p1.afficher();

    // Inverser la pile
    cout << "\nApres inversion :" << endl;
    p1.inverser();
    p1.afficher();


    // Test avec string
    cout << "\n===== PILE DE CHAINES =====" << endl;

    Pile<string> p2;

    p2.empiler("Bonjour");
    p2.empiler("Salut");
    p2.empiler("Bonsoir");

    p2.afficher();

    cout << "Sommet : " << p2.sommet() << endl;


    // Test avec double
    cout << "\n===== PILE DE REELS =====" << endl;

    Pile<double> p3;

    p3.empiler(10.5);
    p3.empiler(20.75);
    p3.empiler(30.25);

    p3.afficher();

    cout << "Sommet : " << p3.sommet() << endl;


    // Test de l'exception
    cout << "\n===== TEST EXCEPTION =====" << endl;

    Pile<int> p4;

    try
    {
        p4.depiler();
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
