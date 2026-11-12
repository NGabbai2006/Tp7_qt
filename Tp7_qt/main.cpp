#include "Tp7_qt.h"
#include <QtWidgets/QApplication>
#include "pile_entier.h"
#include <iostream>
#include "qDebug.h"
#include <limits>
using namespace std;
//Vous devrez réaliser une application en mode console qui utilisera des objets instances de cette classe.
//Définissez les différentes méthodes
//Vous réaliserez un test unitaire qui permettra de vérifier le fonctionnement de la classe.
//Vous testerez la classe de votre voisin avec le programme que vous avez réalisé(cela doit compiler sans retouche du code !Sinon c'est que l'un de vous deux n'a pas respecté les spécifications).
//Vous développerez une interface windows très simple qui permet de tester cette classe.
int t_total = 0;
int t_reussi = 0;

void verifier(const bool condi) {
    
    if (condi) {
        t_total++;
        t_reussi++;
    }
    else {
        t_total++;
    }
    return;
}

void testsUnit()
{
    cout << "=== Tests unitaires ===\n";

    pile_entier p(3);
    verifier(p.vide() == 1);/*Pile vide au start*/
    verifier(p.pleine() == 0); /*Pile non pleine au start*/

    p.empile(10);
    p.empile(20);
    p.empile(30);
    verifier(p.pleine() == 1); /*Pile pleine ca a donc bien empiler tout les nombres*/

    p.empile(40);
    verifier(p.pleine() == 1); /*regarde si ça a bien ignoré l'empilement quand pile pleine*/

    verifier(p.depile() == 30);
    verifier(p.depile() == 20);
    verifier(p.depile() == 10);
    verifier(p.vide() == 1); /*regarde si la Pile est vide apres les 3 depilements*/

    cout << "Resultat: " << t_reussi << "/" << t_total << " tests reussis";
}

void appli_console() {
    int taille = 0;
    cout << "======== Interface console pile_entier ======\n";
    cout << "taille de la pile : ";

    do {
        cin >> taille;
        if (!taille || taille <=0) {
            cout << "taille invalide.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
	} while (taille <= 0);

    pile_entier p(taille);

    int choix = 0;
    while (choix != 4) {
        cout << "\n1) Empiler\n";
        cout << "2) Depiler\n";
        cout << "3) Etat (vide/pleine)\n";
        cout << "4) Quitter\n";
        cout << "Choix : ";

        if (!(cin >> choix)) {
            cout << "choix invalide.\n";
			cin.clear(); // suppr les anciennes erreurs
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //vide le buffer 
			continue; // permet re tourner au début de la boucle while
        }

        switch (choix) {
        case 1: {
            int valeur = 0;
            cout << "Valeur a empiler : ";
			cin >> valeur;
            if (!valeur) {
                cout << "valeur invalide.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            if (p.pleine() == 1) {
                cout << "Pile pleine, impossible d'empiler.\n";
            }
            else {
                p.empile(valeur);
                cout << "Valeur empilee.\n";
            }
            break;
        }
        case 2:
            if (p.vide() == 1) {
                cout << "pile vide, impossible de depiler.\n";
            }
            else {
                cout << "valeur depilee : " << p.depile() << "\n";
            }
            break;
        case 3:
            if (p.vide() == 1) {
                cout << "La pile est vide.\n";
            }
            else if (p.pleine() == 1) {
                cout << "La pile est pleine.\n";
            }
            else {
                cout << "La pile n'est ni vide ni pleine.\n";
			}

            break;
        case 4:
            break;
        }
    }
}
int main(int argc, char *argv[])
{

	int choix = 0;
    cout << "1) Tests unitaires\n";
    cout << "2) Application console\n";
    cout << "3) Application Qt\n";
    cout << "Choix : ";
    
    cin >> choix;
    switch (choix) {
    case 1:
        testsUnit();
        return 0;
    case 2:
        appli_console();
        return 0;
    case 3:
        break;
    }

    QApplication app(argc, argv);
    Tp7_qt window;
    window.show();
    return app.exec();
}
