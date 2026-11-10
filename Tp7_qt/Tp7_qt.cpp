#include "Tp7_qt.h"
#include "qDebug.h"
#include <QListWidget>

const int taille = 20;

Tp7_qt::Tp7_qt(QWidget *parent): QMainWindow(parent),pile(taille)
{
    ui.setupUi(this);
    connect(ui.ButtonEmpile, &QPushButton::clicked, this, &Tp7_qt::OnClickButtonEmpile);
    connect(ui.ButtonDepile, &QPushButton::clicked, this, &Tp7_qt::OnClickButtonDepile);
    hauteur = 0;
    t = taille;
}

Tp7_qt::~Tp7_qt()
{
}

void Tp7_qt::OnClickButtonEmpile() {
    QString msg;
    if (pile.pleine() == 1) {
        msg = "votre pile est pleine, impossible d'ajouter un nombre";
        ui.infoPile->setText(msg);
        return;
    }
    else {
        bool ok;
        QString chiffre = ui.chiffreEmpile->text();
        if (!chiffre.toInt(&ok)) {
            msg = "un nombre ou chiffre !! ";
            ui.infoPile->setText(msg);
            return;
        }
        else {
            int nb = chiffre.toInt();
            pile.empile(nb);
            hauteur++;
            msg = chiffre + " a ete empile";
            ui.infoPile->setText(msg);
            ui.infoHauteur->setText(QString::number(hauteur) + "/"+QString::number(t));
            QListWidgetItem* ligne = new QListWidgetItem(QString::number(hauteur) + "| " + chiffre);
            ui.ListPile->addItem(ligne);
            
        }
    }

}

void Tp7_qt::OnClickButtonDepile() {
    QString msg;
    if (pile.vide() == 1) {
        msg = "votre pile est vide, impossible de retirer un nombre";
        ui.infoPile->setText(msg);
        return;
    }
    else {
        int nb = pile.depile();

        msg = "votre pile a depile : " + QString::number(nb);
        ui.infoPile->setText(msg);
        ui.infoHauteur->setText(QString::number(hauteur) + "/"+QString::number(t));
        ui.ListPile->takeItem(hauteur);
        hauteur--;
    }
    return;
}
