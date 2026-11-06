#pragma once
#pragma warning(disable:4996)

#include <QtWidgets/QMainWindow>
#include "ui_Tp7_qt.h"
#include "pile_entier.h"

class Tp7_qt : public QMainWindow
{
    Q_OBJECT

public:
    Tp7_qt(QWidget *parent = nullptr);
    ~Tp7_qt();
    void OnClickButtonEmpile(pile_entier p);
    void OnClickButtonDepile(pile_entier p);
    void OnClickButtonAffiche(pile_entier p);

private:
    Ui::Tp7_qtClass ui;
};

