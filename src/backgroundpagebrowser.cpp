#include "backgroundpagebrowser.h"
#include <QWebEngineView>
#include <QTextStream>
#include <QVBoxLayout>
#include <QIODevice>
#include <QString>
#include <QFile>
#include <QDir>

QWebEngineView *browser;

BackgroundPageBrowser::BackgroundPageBrowser(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *l = new QVBoxLayout();
    browser = new QWebEngineView(parent);
    browser->page()->setBackgroundColor(Qt::transparent);
    QFile file(QDir::homePath() + "/.backgroundPageConfig");
    QString urlString = "";

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        if(!in.atEnd())
        {
            urlString = in.readLine();
        }
        file.close();
    }


connect(browser, SIGNAL(loadFinished(bool)), SLOT(onLoadFinished(bool)));
browser->load(QUrl(urlString));
    l->addWidget(browser, 1);
    l->layout()->setContentsMargins(0,0,0,0);
    setLayout(l);
}

BackgroundPageBrowser::~BackgroundPageBrowser()
{
}

void BackgroundPageBrowser::onLoadFinished(bool success)
{
    if ( ! success )
    {
        browser->load(QUrl("file:///" + QDir::homePath() + "/backgroundPageLocal/index.html"));
    }
}
