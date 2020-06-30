#ifndef ALBUMDAO_H
#define ALBUMDAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class Album;

class AlbumDao
{

public:

    AlbumDao(QSqlDatabase& database);
    void create() const;

    void addAlbum(Album& album) const;
    void updateAlbum(const Album& album) const;
    void removeAlbum(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> albums() const;
//    auto albumes() const;

private:
    QSqlDatabase& mDatabase;
};

#endif // ALBUMDAO_H
