#include "Tp7_qt.h"
#include <QtWidgets/QApplication>
#include "pile_entier.h"
#include <iostream>
//Vous devrez réaliser une application en mode console qui utilisera des objets instances de cette classe.
//Définissez les différentes méthodes
//Vous réaliserez un test unitaire qui permettra de vérifier le fonctionnement de la classe.
//Vous testerez la classe de votre voisin avec le programme que vous avez réalisé(cela doit compiler sans retouche du code !Sinon c'est que l'un de vous deux n'a pas respecté les spécifications).
//Vous développerez une interface windows très simple qui permet de tester cette classe.


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Tp7_qt window;
    window.show();
    return app.exec();
}
