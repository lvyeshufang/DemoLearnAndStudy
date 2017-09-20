#ifndef _CSTYLE_SHEET_CENTER_H_
#define _CSTYLE_SHEET_CENTER_H_

#include <QtCore/QtCore>

namespace XP
{
    class CStyleSheetCenter
    {
    public:
        CStyleSheetCenter();
        ~CStyleSheetCenter();

        void parse(QString qsXml);
        void reparse();

        QString getStyle(QString qsKey) const;

    protected:
        void setStyle(QString qsKey, QString qsStyle);

        QString                 m_strSchemeName;
        int                     m_nSchemeID;
        QMap<QString, QString>      m_styleMap;
        QString                     m_strDefaultStyle;
        QString                     m_strFileName;
    };
}


#endif //_CSTYLE_SHEET_CENTER_H_
