#include "downloadfactory.h"

downloadFactory::downloadFactory(QObject *parent) :
    QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

downloadFactory &downloadFactory::get()
{
    static downloadFactory obj;
    return obj;
}

void downloadFactory :: enqueue(QUrl u, priority p)
{
    switch (p)
    {
    case low:   lowPriority.enqueue(u);break;
    case high: highPriority.enqueue(u);break;
    }
}

