/*
 *  Filename	: ShellcodeInfo.h
 *  Author		: Kuba Sejdak
 *  Created on	: 03-05-2012
 */

#ifndef SHELLCODEINFO_H_
#define SHELLCODEINFO_H_

#include <QMultiMap>
#include <QMap>
#include <QList>
#include <QString>
#include <QtSql>
#include <stdint.h>
#include <iostream>
#include <iomanip>
using namespace std;

class ShellcodeInfo {
public:
	ShellcodeInfo();
	~ShellcodeInfo();

	void printInfo();

    QString name();
    QString extractedFrom();
    QString graphName();
	int size();
    QString fileType();
	int fileSize();
    int codeOffset();
	bool isShellcodePresent();
    QMultiMap<QString, QMap<QString, QString> *> *traits();
    QList<QSqlQuery> *querys();

    void setName(QString name);
    void setExtractedFrom(QString name);
    void setGraphName(QString name);
	void setSize(int size);
    void setFileType(QString fileType);
	void setFileSize(int fileSize);
	void setCodeOffset(int codeOffset);
	void setShellcodePresent(bool shellcodePresent);
    void setTrait(QString name, QMap<QString, QString> *value);
	void setQuery(QSqlQuery q);

private:
    QString m_name;
    QString m_extractedFrom;
    QString m_graphName;
	int m_size;
    QString m_fileType;
	int m_fileSize;
	int m_codeOffset;
    bool m_shellcodePresent;
    QMultiMap<QString, QMap<QString, QString> *> *m_traits;
    QList<QSqlQuery> *m_querys;
};

#endif /* SHELLCODEINFO_H_ */
