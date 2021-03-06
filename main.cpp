#include <QApplication>
#include <QMessageBox>
#include "window.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(systray);

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("CRCIS");
    QCoreApplication::setOrganizationDomain("CRCIS.noornet.net");
    QCoreApplication::setApplicationName("ConnectToInternet");
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Internet Connection"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        return 1;
    }
    QApplication::setQuitOnLastWindowClosed(false);

    Window window;
    window.show();
    return app.exec();
}
// 
// #else
// 
// #include <QLabel>
// #include <QDebug>
// 
// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);
//     QString text("QSystemTrayIcon is not supported on this platform");
// 
//     QLabel *label = new QLabel(text);
//     label->setWordWrap(true);
// 
//     label->show();
//     qDebug() << text;
// 
//     app.exec();
// }
// 
// #endif
