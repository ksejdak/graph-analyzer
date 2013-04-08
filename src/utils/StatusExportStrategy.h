/*
 *  Filename	: StatusExportStrategy.h
 *  Author		: Kuba Sejdak
 *  Created on	: 02-04-2013
 */

#ifndef STATUSEXPORTSTRATEGY_H
#define STATUSEXPORTSTRATEGY_H

#include <QString>
#include <tasks/ITask.h>
#include <utils/XMLParser.h>

#define STATUS_FILE     "/var/www/jsejdak/GraphAnalyzerStatus.xml"

class IStatusExportStrategy {
public:
    IStatusExportStrategy() {}
    virtual ~IStatusExportStrategy() {}

    virtual void exportStatus(ITask *task) = 0;
    virtual QString description() = 0;
};

class DBStatusExportStrategy : public IStatusExportStrategy {
public:
    DBStatusExportStrategy() {}
    virtual ~DBStatusExportStrategy() {}

    virtual void exportStatus(ITask *task);
    virtual QString description();
};

class XMLStatusExportStrategy : public IStatusExportStrategy {
public:
    XMLStatusExportStrategy() {}
    virtual ~XMLStatusExportStrategy() {}

    virtual void exportStatus(ITask *task);
    virtual QString description();

private:
    XMLParser m_xmlParser;
};

#endif /* STATUSEXPORTSTRATEGY_H */
