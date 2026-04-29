#include "ajouteeleve.h"
#include "ui_ajouteeleve.h"

AjouteEleve::AjouteEleve(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AjouteEleve)
{
    ui->setupUi(this);
}

AjouteEleve::~AjouteEleve()
{
    delete ui;
}

QString AjouteEleve::getNom() const
{
    return ui->nomEdit->text();
}

QString AjouteEleve::getPrenom() const
{
    return ui->prenomEdit->text();
}

int AjouteEleve::getAge() const
{
    return ui->ageSpin->value();
}

QString AjouteEleve::getNiveau() const
{
    return ui->niveauCombo->currentText();
}

void AjouteEleve::on_btnValider_clicked()
{
    accept();
}
void AjouteEleve::setNom(const QString &n)
{
    ui->nomEdit->setText(n);
}

void AjouteEleve::setPrenom(const QString &p)
{
    ui->prenomEdit->setText(p);
}

void AjouteEleve::setAge(int a)
{
    ui->ageSpin->setValue(a);
}

void AjouteEleve::setNiveau(const QString &n)
{
    int index = ui->niveauCombo->findText(n);
    if(index >= 0)
        ui->niveauCombo->setCurrentIndex(index);
}
