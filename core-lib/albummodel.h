#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H



#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "core-lib_global.h"
#include "album.h"
#include "dbmanager.h"

class CORELIB_EXPORT AlbumModel : public QAbstractListModel
{
    Q_OBJECT
public:

    // use enum class (scoped enum) will require static_cast<int> if compared to int
    enum Roles {
        // get last enum value and inc by 1
        IdRole = Qt::UserRole + 1,
        NameRole,
    };

    AlbumModel(QObject* parent = 0);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    bool removeRows(int row, int count, const QModelIndex& parent) override;
    QHash<int, QByteArray> roleNames() const override;

    QModelIndex addAlbum(const Album& album);

private:
    bool isIndexValid(const QModelIndex& index) const;

    DbManager& mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> mAlbums;
};


#endif // ALBUMMODEL_H
