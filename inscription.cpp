#include "inscription.h"
#include "ajouteeleve.h"
#include "./ui_inscription.h"
#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QMessageBox>


inscription::inscription(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inscription)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(
        {"Nom", "Prenom", "Age", "Niveau"}
        );

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    loadData();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

}

inscription::~inscription()
{
    delete ui;
}
void inscription::loadData()
{

    QFile file("data.csv");



    if(!file.exists())
    {
        // créer fichier vide avec header
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << "Nom,Prenom,Age,Niveau\n";
            file.close();
        }
        return;
    }

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        QString line;
        bool firstLine = true;

        while(in.readLineInto(&line))
        {
            if(firstLine)
            {
                firstLine = false;
                continue;
            }

            QStringList data = line.split(",");

            if(data.size() == 4)
            {
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);

                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(data[0]));
                ui->tableWidget->setItem(row, 1, new QTableWidgetItem(data[1]));
                ui->tableWidget->setItem(row, 2, new QTableWidgetItem(data[2]));
                ui->tableWidget->setItem(row, 3, new QTableWidgetItem(data[3]));
            }
        }

        file.close();
    }
}
void inscription::on_ajouter_clicked()
{
    AjouteEleve dialog(this);


    if(dialog.exec() == QDialog::Accepted)
    {
        QString nom = dialog.getNom();
        QString prenom = dialog.getPrenom();
        int age = dialog.getAge();
        QString niveau = dialog.getNiveau();





        //Ajouter dans le tableau
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(nom));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(prenom));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(age)));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(niveau));

        // Sauvegarde dans CSV
        QFile file("data.csv");

        if(file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&file);
            out << nom << "," << prenom << "," << age << "," << niveau << "\n";
            file.close();
        }
    }
}

void inscription::on_supprimer_clicked()
{
    int row = ui->tableWidget->currentRow();

    if(row < 0)
    {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un étudiant !");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this,
        "Confirmation",
        "Voulez-vous vraiment supprimer cet étudiant ?",
        QMessageBox::Yes | QMessageBox::No
        );

    if(reply == QMessageBox::No)
    {
        return;
    }


    ui->tableWidget->removeRow(row);

    saveAllToCSV();
}


void inscription::saveAllToCSV()
{
    QFile file("data.csv");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);

        // header
        out << "Nom,Prenom,Age,Niveau\n";

        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            QString nom = ui->tableWidget->item(i,0)->text();
            QString prenom = ui->tableWidget->item(i,1)->text();
            QString age = ui->tableWidget->item(i,2)->text();
            QString niveau = ui->tableWidget->item(i,3)->text();

            out << nom << "," << prenom << "," << age << "," << niveau << "\n";
        }

        file.close();
    }
}

void inscription::on_modifier_clicked()
{
    int row = ui->tableWidget->currentRow();

    if(row < 0)
    {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un étudiant !");
        return;
    }

    //  récupérer données actuelles
    QString nom = ui->tableWidget->item(row,0)->text();
    QString prenom = ui->tableWidget->item(row,1)->text();
    int age = ui->tableWidget->item(row,2)->text().toInt();
    QString niveau = ui->tableWidget->item(row,3)->text();

    AjouteEleve dialog(this);

    dialog.setNom(nom);
    dialog.setPrenom(prenom);
    dialog.setAge(age);
    dialog.setNiveau(niveau);

    if(dialog.exec() == QDialog::Accepted)
    {
        // récupérer nouvelles valeurs
        QString newNom = dialog.getNom();
        QString newPrenom = dialog.getPrenom();
        int newAge = dialog.getAge();
        QString newNiveau = dialog.getNiveau();

        // mettre à jour tableau
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(newNom));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(newPrenom));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(newAge)));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(newNiveau));

        // sauvegarder CSV
        saveAllToCSV();
    }
}

void inscription::on_searchEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            ui->tableWidget->setRowHidden(i, false);
        }
        return;
    }

    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        bool match = false;

        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);

            if(item && item->text().contains(arg1, Qt::CaseInsensitive))
            {
                match = true;
                break;
            }
        }

        ui->tableWidget->setRowHidden(i, !match);
    }
}


