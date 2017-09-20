#ifndef _STYLE_SHEET_MANAGER_H_
#define _STYLE_SHEET_MANAGER_H_


#include <QtCore/QtCore>

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets/qwidget.h>
#else
#include <QtGui/qwidget.h>
#endif

namespace XP
{
    class CStyleSheetCenter;

    class CStyleSheetManger
    {
    public:
        CStyleSheetManger();
        ~CStyleSheetManger();

        void registerStyle(const QString& qsStyleName, QWidget* pWidget = NULL, bool bIsGlobal = true);
        void resetAllStyle();
        void resetThemeStyle(const QString& qsStyleName);

        void resetConfig();
        void setRoot(QString qsRoot);
        XP::CStyleSheetCenter* getStyleSheetCenter();

    private:
        QList<QString> m_styleGlobal;       //the global style for all widgets.
        QMap<QWidget*, QString> m_styleMap; //the specifical style for one widgets.
        XP::CStyleSheetCenter* m_pStyle;
        QString m_qsRoot;
    };

    extern XP::CStyleSheetManger g_MgrStyle;
}


#endif //_STYLE_SHEET_MANAGER_H_