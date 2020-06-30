#ifndef ALBUM_H
#define ALBUM_H

#include "core-lib_global.h"
#include <QString>

class CORELIB_EXPORT Album
{
public:
    /*
     * explicit:
     *  means constructor arg must match the type with no implicit cast (narrow conversion)
     * std::initializer_list:
     *  used as arg to receive all brace-initialization {}
     *  does not allow narrow conversion (implicit from float to int)
     */
    explicit Album(const QString& name = "");

    /*
     * const:
     *  means this getter func will not modify any member data
     */
    int id() const;
    void setId(int id);
    QString name() const;
    void setName(const QString& name);

private:
    int mId;
    QString mName;
};

#endif // ALBUM_H
