#include "Tp7_qt.h"
#include <QtWidgets/QApplication>
#include "pile_entier.h"
#include <iostream>
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
    std::cout << "=== Tests unitaires ===\n";

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

qDebug() << "Resultat: " << t_reussi << "/" << t_total << " tests reussis";
}

void appli_console() {
    
}
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Tp7_qt window;
    window.show();
    return app.exec();
}
