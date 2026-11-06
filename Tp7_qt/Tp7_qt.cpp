#include "Tp7_qt.h"
#include "qDebug.h"

Tp7_qt::Tp7_qt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.ButtonAfficher, &QPushButton::clicked, this, &Tp7_qt::OnClickButtonAffiche);
    connect(ui.ButtonEmpile, &QPushButton::clicked, this, &Tp7_qt::OnClickButtonEmpile);
    connect(ui.ButtonDepile, &QPushButton::clicked, this, &Tp7_qt::OnClickButtonDepile);
}

Tp7_qt::~Tp7_qt()
{
}

void Tp7_qt::OnClickButtonEmpile(pile_entier p) {
    QString msg;
    if (p.pleine() == 1) {
        msg = "votre pile est pleine, impossible d'ajouter un nombre";
        ui.infoPile->setText(msg);
    }
    else {
        QString chiffre = ui.chiffreEmpile->text();
        int nb = chiffre.toInt();
        p.empile(nb);
        msg = chiffre+" a ete empile";
        ui.infoPile->setText(msg);
    }

}

void Tp7_qt::OnClickButtonDepile(pile_entier p) {
    QString msg;
    qDebug()<< p.vide();
    if (p.vide() == 1) {
        msg = "votre pile est vide, impossible de retirer un nombre";
        ui.infoPile->setText(msg);
    }
    else {
        int nb=p.depile();
        msg = "votre pile a depile : " + nb;
        ui.infoPile->setText(msg);
    }
}

void Tp7_qt::OnClickButtonAffiche(pile_entier p) {
    
}