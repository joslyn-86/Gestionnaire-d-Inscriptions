#include "Personne.h"
#include "ui_Personne.h"

Personne::Personne(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Personne)
{
    ui->setupUi(this);
}

Personne::~Personne()
{
    delete ui;
}

QString Personne::getNom() const
{
    return ui->nomEdit->text();
}

QString Personne::getPrenom() const
{
    return ui->prenomEdit->text();
}

int Personne::getAge() const
{
    return ui->ageSpin->value();
}

QString Personne::getNiveau() const
{
    return ui->niveauCombo->currentText();
}

void Personne::setNom(const QString &n)
{
    ui->nomEdit->setText(n);
}

void Personne::setPrenom(const QString &p)
{
    ui->prenomEdit->setText(p);
}

void Personne::setAge(int a)
{
    ui->ageSpin->setValue(a);
}

void Personne::setNiveau(const QString &n)
{
    int index = ui->niveauCombo->findText(n);
    if(index >= 0)
        ui->niveauCombo->setCurrentIndex(index);
}

void Personne::on_btnValider_clicked()
{
    accept();
}
