#ifndef PICTURE_H
#define PICTURE_H


#include <QUrl>
#include <QString>
#include "core-lib_global.h"

class CORELIB_EXPORT Picture
{
public:
    explicit Picture(const QString& filePath = "");
    explicit Picture(const QUrl& fileUrl);
    int id() const;
    void setId(int id);
    int albumId() const;
    void setAlbumId(int albumId);
    QUrl fileUrl() const;
    void setFileUrl(const QUrl& fileUrl);
private:
    int mId;
    int mAlbumId;
    QUrl mFileUrl;
};
#endif // PICTURE_H
