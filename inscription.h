#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class inscription;
}
QT_END_NAMESPACE

class inscription : public QMainWindow
{
    Q_OBJECT

public:
    inscription(QWidget *parent = nullptr);
    ~inscription();

private slots:
    void on_ajouter_clicked();
    void loadData();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_searchEdit_textChanged(const QString &arg1);

private:
    void saveAllToCSV();

private:
    Ui::inscription *ui;
};
#endif
