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

void MainWindow::findLongestSubstrings()
{
    int counter = 0;
    int lastSubElement = 0;

    substring = ui->lineEdit->text();

    for(auto i = 0; i < ui->listWidget->count(); ++i)
    {
        if (i < SubstringSize.size())
        {
            SubstringSize[i] = 0;
            SubstringCord[i] = QPair<int,int>(0,0);
        }
        else
        {
            SubstringSize.push_back(0);
            SubstringCord.push_back(QPair<int,int>(0,0));
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
                if (counter >= SubstringSize[i])
                {
                    SubstringSize[i] = counter;
                    SubstringCord[i] = QPair<int,int>(j, j + lastSubElement);
                }
            }
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
    for(auto i = 0; i < ui->listWidget->count(); ++i)
    {
        ui->listWidget->item(i)->setText(ui->listWidget->item(i)->text().toLower());
    }

    if (ui->lineEdit->text().size() > 0)
    {
        findLongestSubstrings();

        int biggestSubstringSize = * std::max_element(SubstringSize.begin(),SubstringSize.end());

        for (auto i = 0; i < SubstringSize.size(); ++i)
        {
            if (biggestSubstringSize == SubstringSize[i] && biggestSubstringSize > 0)
            {
              tmp = ui->listWidget->item(i)->text();
              for (auto j = SubstringCord[i].first; j <= SubstringCord[i].second; ++j)
              {
                  tmp[j]=tmp[j].toUpper();
              }

              ui->listWidget->item(i)->setText(tmp);

            }
        }
    }

    ui->listWidget->update();

    ui->lineEdit->setText("");
}
