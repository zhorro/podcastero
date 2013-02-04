#ifndef DOWNLOADFACTORY_H
#define DOWNLOADFACTORY_H

#include <QObject>
#include <QQueue>
#include <QPair>
#include <QUrl>
#include <QNetworkRequest>

#include <QNetworkAccessManager>

class downloadFactory : public QObject
{
    Q_OBJECT
    explicit downloadFactory(QObject *parent = 0);

// Сетевой кусок
    QNetworkAccessManager * manager;

    QQueue <QPair<QUrl, QNetworkRequest> > progress;
    QQueue <QUrl> highPriority;
    QQueue <QUrl> lowPriority;
public:
    enum priority { low, high };
    static downloadFactory & get();

public slots:
    void enqueue(QUrl, priority = low);
};

#endif // DOWNLOADFACTORY_H

