#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

const int N = 5;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addRow();
    void paintGreen(int column);
    void paintRed(int column);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int a[N];
};

#endif // MAINWINDOW_H
