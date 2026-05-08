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
    void on_searchEdit_textChanged(const QString &arg1);
    void on_prevBtn_clicked();
    void on_nextBtn_clicked();
    void updateTableDisplay();
    void showContextMenu(const QPoint &pos);

private:

    Ui::inscription *ui;
    void saveAllToCSV();
    void supprimerLigne(int row);
    void modifierLigne(int row);
    int currentPage = 0;
    int rowsPerPage = 19;
};
#endif
