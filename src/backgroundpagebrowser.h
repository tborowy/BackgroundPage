#ifndef BACKGROUNDPAGEBROWSER_H
#define BACKGROUNDPAGEBROWSER_H

#include <QWidget>

class BackgroundPageBrowser : public QWidget
{
    Q_OBJECT

public:
    BackgroundPageBrowser(QWidget *parent = (QWidget *)NULL);
    virtual ~BackgroundPageBrowser();

public slots:
     void onLoadFinished(bool success);
signals:
     void loadFinished(bool success);
};

#endif
