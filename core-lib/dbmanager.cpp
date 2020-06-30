#include "dbmanager.h"

#include <QSqlDatabase>
#include <QSqlQuery>

DbManager& DbManager::instance()
{
    static DbManager singleton;
    return singleton;
}
DbManager::DbManager(const QString& path) :
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    albumDao(*mDatabase),
    pictureDao(*mDatabase)
{
    mDatabase->setDatabaseName(path);
    mDatabase->open();

    albumDao.create();
    pictureDao.create();
}
DbManager::~DbManager()
{
    mDatabase->close();
    // no need to do: delete mDatabase;
}
