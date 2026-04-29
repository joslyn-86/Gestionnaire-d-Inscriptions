#ifndef AJOUTEELEVE_H
#define AJOUTEELEVE_H

#include <QDialog>

namespace Ui {
class AjouteEleve;
}

class AjouteEleve : public QDialog
{
    Q_OBJECT

public:
    explicit AjouteEleve(QWidget *parent = nullptr);
    ~AjouteEleve();
    void setNom(const QString &n);
    void setPrenom(const QString &p);
    void setAge(int a);
    void setNiveau(const QString &n);

public:
    QString getNom() const;
    QString getPrenom() const;
    int getAge() const;
    QString getNiveau() const;

private slots:
    void on_btnValider_clicked();


private:
    Ui::AjouteEleve *ui;
};

#endif
