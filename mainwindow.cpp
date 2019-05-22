#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::defaultListCase()
{
    for(auto i = 0; i < ui->listWidget->count(); ++i)
    {
        ui->listWidget->item(i)->setText(ui->listWidget->item(i)->text().toLower());
    }
}

void MainWindow::findLongestSubstrings()
{
    int counter = 0;
    int lastSubElement = 0;

    substring = ui->lineEdit->text();

    for(auto i = 0; i < ui->listWidget->count(); ++i)
    {
        if (i < substringSize.size())
        {
            substringSize[i] = 0;
        }
        else
        {
            substringSize.push_back(0);
        }

        tmp = ui->listWidget->item(i)->text();

        for (auto j = 0; j < tmp.size(); ++j)
        {
            if(tmp[j] == substring[0])
            {
                counter = 0;
                lastSubElement = 0;

                for (auto e = j; e < tmp.size(); ++e)
                {
                    if (tmp[e] == substring[e - j])
                    {
                        ++counter;

                        if( (e - j) > lastSubElement)
                        {
                            lastSubElement = e - j;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if (counter >= substringSize[i])
                {
                    substringSize[i] = counter;
                    Record tmpRecord (i, j, j + lastSubElement);
                    substringCord.push_back(tmpRecord);
                }
            }
        }
    }
}

void MainWindow:: changeText()
{
    if (ui->lineEdit->text().size() > 0)
    {
        findLongestSubstrings();

        for (auto i = 0; i < substringCord.size(); ++i)
        {

            tmp = ui->listWidget->item(substringCord[i].getStrNumber())->text();

            for (auto j = substringCord[i].getCordinatesFirst(); j <= substringCord[i].getCordinatesSecond(); ++j)
            {
                tmp[j]=tmp[j].toUpper();
            }

            ui->listWidget->item(substringCord[i].getStrNumber())->setText(tmp);

        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    new QListWidgetItem(ui->lineEdit_2->text().toLower(), ui->listWidget);
    ui->lineEdit_2->setText("");
}

void MainWindow::on_pushButton_clicked()
{
    substringCord.clear();

    defaultListCase();

    changeText();

    ui->listWidget->update();

    ui->lineEdit->setText("");
}
