#include "picturedao.h"


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "picture.h"
#include "dbmanager.h"

using namespace std;

PictureDao::PictureDao(QSqlDatabase& database) :
    mDatabase(database)
{
}

void PictureDao::create() const
{
    if (!mDatabase.tables().contains("pictures")) {
        QSqlQuery query(mDatabase);
        query.exec(QString("CREATE TABLE pictures")
        + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
        + "album_id INTEGER, "
        + "url TEXT)");
    }
}

void PictureDao::addPictureInAlbum(int albumId, Picture& picture) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("INSERT INTO pictures")
        + " (album_id, url)"
        + " VALUES ("
        + ":album_id, "
        + ":url"
        + ")");
    query.bindValue(":album_id", albumId);
    query.bindValue(":url", picture.fileUrl());
    query.exec();
    picture.setId(query.lastInsertId().toInt());
    picture.setAlbumId(albumId);
}

void PictureDao::removePicture(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM pictures WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

void PictureDao::removePicturesForAlbum(int albumId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM pictures WHERE album_id = (:album_id)");
    query.bindValue(":album_id", albumId);
    query.exec();
}

unique_ptr<vector<unique_ptr<Picture>>> PictureDao::picturesForAlbum(int albumId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM pictures WHERE album_id = (:album_id)");
    query.bindValue(":album_id", albumId);
    query.exec();
    unique_ptr<vector<unique_ptr<Picture>>> list(new vector<unique_ptr<Picture>>());
    while(query.next()) {
        unique_ptr<Picture> picture(new Picture());
        picture->setId(query.value("id").toInt());
        picture->setAlbumId(query.value("album_id").toInt());
        picture->setFileUrl(query.value("url").toString());
        list->push_back(move(picture));
    }
    // return will call implicitly std::move so ownership moved to caller scope
    return list;
}
