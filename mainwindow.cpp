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

    mainstring = ui->lineEdit->text(); //reading mainstring

    for (auto i = 0; i < ui->listWidget->count(); ++i)
    {
        tmp = ui->listWidget->item(i)->text();// readeing substrings

        if (tmp.size() > mainstring.size())
        {
            continue;
        }

        substringSize.push_back(0); //filling vector by default values

        for (auto j = 0; j < mainstring.size(); ++j)
        {
            counter = 0;
            if (mainstring[j] == tmp[0])
            {
                for (auto e = j; e < mainstring.size(); ++e)
                {
                    if (mainstring[e] == tmp[e - j] && counter < tmp.size())
                    {
                        ++counter; //Counting the same letters
                    }
                    else
                    {
                        break;
                    }
                }
                if (counter > substringSize[i] && counter == tmp.size())
                {
                    substringSize[i] = counter;
                }
            }
        }
    }
}

void MainWindow:: changeText()
{
    for (auto i = 0; i < ui->listWidget->count(); ++i)
    {
        ui->listWidget->item(i)->setForeground(Qt::black); //Returning default color
    }

    if (ui->lineEdit->text().size() > 0)
    {
        findLongestSubstrings();  //Function searcher of the longest substrings
    }

    int biggestSubstringElement = *std::max_element(substringSize.begin(),substringSize.end());


    if (biggestSubstringElement > 0)
    {
        for (auto i = 0; i < ui->listWidget->count(); ++i)
        {
            if (substringSize[i] == biggestSubstringElement )
            {
                ui->listWidget->item(i)->setForeground(Qt::red); //Painting list
            }
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if( ui->lineEdit_2->text() != "")
    {
        new QListWidgetItem(ui->lineEdit_2->text(), ui->listWidget); //Adding new element to the list
        ui->lineEdit_2->setText("");
    }
}

void MainWindow::on_pushButton_clicked()
{
    substringSize.clear();

    changeText();
}
