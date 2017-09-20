#include "CStyleSheetCenter.h"
#include <QtXml/QtXml>

namespace XP
{
    CStyleSheetCenter::CStyleSheetCenter()
        :m_strSchemeName("")
        ,m_nSchemeID(-1)
        ,m_strDefaultStyle("")
        ,m_strFileName("")
    {
    }


    CStyleSheetCenter::~CStyleSheetCenter()
    {
    }

    void CStyleSheetCenter::parse(QString qsXml)
    {
        /*
        QString qsFileName = XP::getResourceDir() + QDir::separator() + "font" + QDir::separator() + qsThemeName + QDir::separator() + "size.xml";
        */

        m_strFileName = qsXml;

        QDomDocument xmlDomParser;
        QFile qFile(qsXml);

        if (!qFile.open(QIODevice::ReadOnly))
        {
            return;
        }

        if (!xmlDomParser.setContent(&qFile))
        {
            qFile.close();
            return;
        }

        QDomNode node = xmlDomParser.firstChild();
        if (!node.isNull())
        {
            while (node.nodeName() != "stylescheme")
            {
                node = node.nextSibling();
            }

            QDomElement rootElement = node.toElement();
            m_strSchemeName = rootElement.attribute("name");
            m_nSchemeID = rootElement.attribute("id").toInt();

            for (QDomElement element = node.firstChildElement(); element.nodeName() == "style"; element = element.nextSiblingElement())
            {
                QDomAttr attr = element.attributeNode("name");
                QString qsStyleName = attr.nodeValue();

                QString qsStyleText = element.text();

                setStyle(qsStyleName, qsStyleText);
            }
        }

        qFile.close();
    }

    void CStyleSheetCenter::reparse()
    {
        if (!m_strFileName.isEmpty())
        {
            parse(m_strFileName);
        }
    }

    QString CStyleSheetCenter::getStyle(QString qsKey) const
    {
         QMap<QString, QString>::const_iterator cIter = m_styleMap.find(qsKey);
        if (cIter != m_styleMap.end())
        {
            return *cIter;
        }
        return m_strDefaultStyle;
    }

    void CStyleSheetCenter::setStyle(QString qsKey, QString qsStyle)
    {
        m_styleMap[qsKey] = qsStyle;
    }

}
