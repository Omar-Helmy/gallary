#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include "albumdao.h"
#include "picturedao.h"
#include <memory>

// QSqlDatabase is forward-declared to be used as pointer, not to include its header file
// and cause unneeded dependency if this lib is used
class QSqlDatabase;
class QSqlQuery;

const QString DATABASE_FILENAME = "gallery.db";

class DbManager
{
public:

    // public: to be accessed from dbmanager
    // const: not to be edited
    const AlbumDao albumDao;
    const PictureDao pictureDao;

    /*
     *  singleton pattern:
     *  - declare static func that returns ref to single static object (can be any name)
     *  - make default constructor private
     *  - make the copy constructor and copy assignment operator public and delete
     */
    static DbManager& instance();
    DbManager(DbManager const &) = delete;

    virtual ~DbManager();

protected:
    // default constructor (and one with default arg) is private
    DbManager(const QString& path = DATABASE_FILENAME);

    // assignment constructor
    DbManager& operator=(const DbManager& rvalue);

private:

    /*
     * unique_ptr
     *  - has exclusive ownership of the raw pointer
     *  - has {} scope lifetime, then will auto delete
     *  - can be moved, but not copied
     *  - use -> to access raw ptr, and . to access unique ptr functions
     *  - use * operator to return reference to data pointed to by raw pointer
     */
    std::unique_ptr<QSqlDatabase> mDatabase;

};

#endif // DBMANAGER_H
