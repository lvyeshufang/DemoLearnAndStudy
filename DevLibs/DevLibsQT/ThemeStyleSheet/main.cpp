#include "MainWindow.h"
#include <QtWidgets/QApplication>


#include "StyleSheetManger.h"
#include "CStyleSheetCenter.h"
using namespace XP;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    g_MgrStyle.setRoot(QApplication::applicationDirPath());

    MainWindow w;


    w.show();
    return a.exec();
}
