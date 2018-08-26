#include "backgroundpagebrowser.h"
#include <QWebEngineView>
#include <QApplication>
#include <QScreen>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    BackgroundPageBrowser backgroundPage;
    QRect rect = app.screens().at(0)->availableGeometry();

    backgroundPage.setAttribute(Qt::WA_ShowWithoutActivating);

    backgroundPage.setWindowFlags(
                Qt::WindowDoesNotAcceptFocus
                |Qt::FramelessWindowHint
                |Qt::Tool
                |Qt::WindowStaysOnBottomHint
    );

    backgroundPage.resize(rect.width(),rect.height());
    backgroundPage.lower();
    backgroundPage.show();
    return app.exec();
}
