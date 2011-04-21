#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600, 400);

    for (int i = 0; i < N; i ++)
//        a[i] = N - i + 1;
        a[i] = (i * 3 + 2) % N + 1;

// QTableWidget
    ui->tableWidget->setColumnCount(N);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

    addRow();

    for (int iter = 0; iter < N - 1; iter ++)
        for (int i = 0; i < N - 1; i ++)
	{ // a[i], a[i + 1]
            addRow();
            if (a[i] <= a[i + 1]) // ok
	    {
                paintGreen(i);
                paintGreen(i + 1);
	    }
	    else // swap
	    {
                int tmp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = tmp;

                paintRed(i);
                paintRed(i + 1);
	    }
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRow()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    for (int i = 0; i < N; i ++)
    	ui->tableWidget->setItem(
		ui->tableWidget->rowCount() - 1, i,
		new QTableWidgetItem(QString::number(a[i])));
}

void MainWindow::paintGreen(int column)
{
    ui->tableWidget->item(ui->tableWidget->rowCount() - 1,
    	column)->setBackground(QBrush(Qt::green));
}

void MainWindow::paintRed(int column)
{
    ui->tableWidget->item(ui->tableWidget->rowCount() - 1,
    	column)->setBackground(QBrush(Qt::red));
}

