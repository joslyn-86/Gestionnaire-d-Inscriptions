#ifndef Inscription_H
#define Inscription_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Inscription;
}
QT_END_NAMESPACE

class Inscription : public QMainWindow
{
    Q_OBJECT

public:
    Inscription(QWidget *parent = nullptr);
    ~Inscription();

private slots:
    void on_ajouter_clicked();
    void loadData();
    void on_searchEdit_textChanged(const QString &arg1);
    void on_prevBtn_clicked();
    void on_nextBtn_clicked();
    void updateTableDisplay();
    void showContextMenu(const QPoint &pos);

private:

    Ui::Inscription *ui;
    void saveAllToCSV();
    void supprimerLigne(int row);
    void modifierLigne(int row);
    int currentPage = 0;
    int rowsPerPage = 19;
};
#endif
