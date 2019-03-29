#include <QApplication>
#include <QWebEngineView>
//#include <QWebEngineProfile>
//#include <QWebEngineCookieStore>
//#include <QDir>
#include <QIcon>
//#include <QDebug>


int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/res/logo.png"));

    QWebEngineView view;
    view.setUrl(QUrl("https://note.youdao.com/signIn/index.html?&callback=https%3A%2F%2Fnote.youdao.com%2Fweb%2F&from=web"));

    view.showMaximized();


//    QWebEngineProfile * engineProfile = view.page()->profile();
//    engineProfile->setCachePath(QDir::tempPath() + "/youdao"); //删除缓存

//    QWebEngineCookieStore *cookie = engineProfile->cookieStore();
//    cookie->deleteAllCookies(); //删除cookie
//    QString cachePath = engineProfile->cachePath();
//    qDebug() << cachePath;
//    QDir cachePathDir(cachePath);
//    qDebug() << cachePathDir;
//    if (cachePathDir.exists())
//    {
//        bool rlt = cachePathDir.rmdir(cachePath); //删除缓存目录
//        if (!rlt)
//        {
//            qDebug() << cachePathDir;
//        }
//    }


    return app.exec();
}
