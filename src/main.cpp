#include "webview.h"

#include <QApplication>
#include <QHotkey>

int main(int argc, char *argv[])
{
#ifdef Q_OS_ANDROID
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/res/logo.png"));


    WebView view;
    view.setUrl(QUrl("https://note.youdao.com/signIn/index.html?&callback=https%3A%2F%2Fnote.youdao.com%2Fweb%2F&from=web"));

    view.showMaximized();


    //添加快捷键
    QHotkey hotkey(QKeySequence("ctrl+alt+Q"), true);//The hotkey will be automatically registered
    qDebug() << "Is Registered: " << hotkey.isRegistered();

    QObject::connect(&hotkey, &QHotkey::activated, qApp, [&](){
        qDebug() << "Hotkey Activated - the application will quit now";
        qApp->quit();
    });

    QHotkey hotkShow(QKeySequence("ctrl+alt+D"), true);//The hotkey will be automatically registered
    QObject::connect(&hotkShow, &QHotkey::activated, &view, &WebView::hotKeyShowOrHide);

    return app.exec();
}
