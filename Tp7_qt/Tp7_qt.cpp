#include "Tp7_qt.h"
#include "qDebug.h"
#include <QListWidget>

Tp7_qt::Tp7_qt(QWidget *parent): QMainWindow(parent),pile(20)
{
    ui.setupUi(this);
    connect(ui.ButtonEmpile, &QPushButton::clicked, this, &Tp7_qt::OnClickButtonEmpile);
    connect(ui.ButtonDepile, &QPushButton::clicked, this, &Tp7_qt::OnClickButtonDepile);
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
            msg = chiffre + " a ete empile";
            ui.infoPile->setText(msg);
            ui.infoHauteur->setText(QString::number(pile.recupHauteur()) + "/20");
            QListWidgetItem* ligne = new QListWidgetItem(QString::number(pile.recupHauteur()) + "| " + chiffre);
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
        ui.infoHauteur->setText(QString::number(pile.recupHauteur()) + "/"+QString::number(pile.recupTaille()));
        ui.ListPile->takeItem(pile.recupHauteur());
    }
    return;
}
