#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
#include <string>
#include <QStringListModel>
#include <algorithm>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringList list;
    QString substring;
    QString tmp;
    QVector <int> SubstringSize;
    QVector <QPair<int,int>> SubstringCord;


    void findLongestSubstrings();

};

#endif // MAINWINDOW_H
