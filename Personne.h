#ifndef Personne_H
#define Personne_H

#include <QDialog>

namespace Ui {
class Personne;
}

class Personne : public QDialog
{
    Q_OBJECT

public:
    explicit Personne(QWidget *parent = nullptr);
    ~Personne();
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
    Ui::Personne *ui;
};

#endif
