#include "StyleSheetManger.h"
#include "CStyleSheetCenter.h"

#include <QApplication>
#include <QStyle>

namespace XP
{
    CStyleSheetManger g_MgrStyle;


    CStyleSheetManger::CStyleSheetManger()
        : m_pStyle(NULL)
        , m_qsRoot("")
    {
//         QString qsRoot = m_qsRoot;// QApplication::applicationDirPath();
//         QString qsFileName = qsRoot + "/uistyle.xml";
//         m_pStyle = new XP::CStyleSheetCenter();
//         m_pStyle->parse(qsFileName);
    }


    CStyleSheetManger::~CStyleSheetManger()
    {
        if (!m_styleGlobal.isEmpty())
        {
            m_styleGlobal.clear();
        }

        if (!m_styleMap.isEmpty())
        {
            m_styleMap.clear();
        }
    }

    void CStyleSheetManger::registerStyle(const QString& qsStyleName, QWidget* pWidget /*= NULL*/, bool bIsGlobal /*= true*/)
    {
        if (qsStyleName.isEmpty())
        {
            return;
        }

        if (bIsGlobal)
        {
            m_styleGlobal.push_back(qsStyleName);
            return;
        }

        if (NULL != pWidget && NULL != m_pStyle)
        {
            m_styleMap[pWidget] = qsStyleName;
            QString qsStyle = m_pStyle->getStyle(qsStyleName);
            if (!qsStyle.isEmpty())
            {
                pWidget->setStyleSheet(qsStyle);
            }
        }

    }

    void CStyleSheetManger::resetAllStyle()
    {
        QMap<QWidget*, QString>::iterator iter = m_styleMap.begin();
        while (iter != m_styleMap.end() && NULL != m_pStyle)
        {
            QWidget* pWidget = iter.key();
            QString qsStyle = m_pStyle->getStyle(iter.value());
            if (NULL != pWidget && !qsStyle.isEmpty())
            {
                pWidget->setStyleSheet(qsStyle);
            }
            ++iter;
        } 
    }

    void CStyleSheetManger::resetThemeStyle(const QString& qsStyleName)
    {
        QMap<QWidget*, QString>::iterator iter = m_styleMap.begin();
        while (iter != m_styleMap.end() && NULL != m_pStyle)
        {
            QWidget* pWidget = iter.key();
            //QString qsStyle = m_pStyle->getStyle(iter.value());
            if (NULL != pWidget /*&& !qsStyle.isEmpty()*/)
            {
                //pWidget->setStyleSheet(qsStyle);
                pWidget->setProperty("StyleID", qsStyleName);
                pWidget->style()->unpolish(pWidget);
                pWidget->style()->polish(pWidget);
            }
            ++iter;
        }
    }

    void CStyleSheetManger::resetConfig()
    {
        if (NULL != m_pStyle)
        {
            m_pStyle->reparse();
        }
    }

    void CStyleSheetManger::setRoot(QString qsRoot)
    {
        m_qsRoot = qsRoot;

        //QString qsRoot = m_qsRoot;// QApplication::applicationDirPath();
        QString qsFileName = qsRoot + "/../config/uistyle.xml";
        m_pStyle = new XP::CStyleSheetCenter();
        m_pStyle->parse(qsFileName);
    }

    XP::CStyleSheetCenter* CStyleSheetManger::getStyleSheetCenter()
    {
        return m_pStyle;
    }

}