#ifndef DEMO_H
#define DEMO_H

#include <QtWidgets/QMainWindow>


class QLineEdit;
class QTreeWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    public slots:
    void button00_clicked();
    void button01_clicked();
    void button1_clicked();
    void button2_clicked();


private:
    QLineEdit   * m_pLineEdt; 
    QTreeWidget* m_pTreeWidget;
};

#endif // DEMO_H
