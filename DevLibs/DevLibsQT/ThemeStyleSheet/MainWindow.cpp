#include "MainWindow.h"
#include <QApplication>
#include <QWidget>
#include <QStyle>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTreeWidget>
//#include <QTreeWidgetItem>


#include "StyleSheetManger.h"
using namespace XP;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_pLineEdt(NULL)
{
    setCentralWidget(new QWidget(this));
    QWidget* pWidget = centralWidget();
    if (NULL != pWidget)
    {
        QPushButton * pButtonExit = new QPushButton(this);
        QPushButton * pButton00 = new QPushButton(this);
        QPushButton * pButton01 = new QPushButton(this);
        QPushButton * pButton1 = new QPushButton(this);
        QPushButton * pButton2 = new QPushButton(this);
        m_pLineEdt = new QLineEdit(this);


        pButtonExit->resize(80, 40);
        pButtonExit->setText("Exit");
        QObject::connect(pButtonExit, SIGNAL(clicked()), qApp, SLOT(quit()));

        pButton00->resize(80, 40);
        pButton00->setText("configuration");
        QObject::connect(pButton00, SIGNAL(clicked()), this, SLOT(button00_clicked()));
        pButton01->resize(80, 40);
        pButton01->setText("stylesheet");
        QObject::connect(pButton01, SIGNAL(clicked()), this, SLOT(button01_clicked()));

        pButton1->resize(80, 40);
        pButton1->setText("metro");
        QObject::connect(pButton1, SIGNAL(clicked()), this, SLOT(button1_clicked()));

        pButton2->resize(80, 40);
        pButton2->setText("new");
        QObject::connect(pButton2, SIGNAL(clicked()), this, SLOT(button2_clicked()));

        m_pLineEdt->setObjectName("m_pLineEdt");
        m_pLineEdt->setText("ABCDEFGHIJKLMN");
        m_pLineEdt->setToolTip("Click the button to change the control style.");
        m_pLineEdt->resize(80, 40);


        QStringList qsl;
        qsl << tr("Node-01") << tr("Node-02") << tr("Node-03") << tr("Node-04") << tr("Node-05");
        m_pTreeWidget = new QTreeWidget(this);
        QTreeWidgetItem* pItem1 = NULL, *pItem2 = NULL;
        m_pTreeWidget->setColumnCount(5);
        //m_pTreeWidget->setStyleSheet(ss_02);

        for (int index = 0; index < 5; index++) {
            pItem1 = new QTreeWidgetItem(qsl);
            pItem2 = new QTreeWidgetItem(qsl);
            pItem1->addChild(pItem2);
            m_pTreeWidget->addTopLevelItem(pItem1);
        }


        g_MgrStyle.registerStyle("ss_line_edit", m_pLineEdt, false);
        g_MgrStyle.registerStyle("ss_tree_view", m_pTreeWidget, false);
        g_MgrStyle.registerStyle("ss_main_form", this, false);
        
        QVBoxLayout* pLayoutMain = new QVBoxLayout();
        QHBoxLayout* pLayout = new QHBoxLayout();
        if (NULL != pLayout && NULL != pLayoutMain)
        {
            pLayout->setSpacing(0);
            pLayout->setMargin(0);
            pLayout->addWidget(pButtonExit);
            pLayout->addWidget(pButton00);
            pLayout->addWidget(pButton01);
            pLayout->addWidget(pButton1);
            pLayout->addWidget(pButton2);

            pLayoutMain->addLayout(pLayout);
            pLayoutMain->addWidget(m_pLineEdt);
            pLayoutMain->addWidget(m_pTreeWidget);
            pLayoutMain->addStretch(1);
            pWidget->setLayout(pLayoutMain);
        }
    }

    this->resize(600, 500);
}

MainWindow::~MainWindow()
{

}

void MainWindow::button00_clicked()
{
    g_MgrStyle.resetConfig();
}


void MainWindow::button01_clicked()
{
    g_MgrStyle.resetAllStyle();}

void MainWindow::button1_clicked()
{
    g_MgrStyle.resetThemeStyle("metro");
}

void MainWindow::button2_clicked()
{
    g_MgrStyle.resetThemeStyle("new");
}
