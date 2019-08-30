#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebEngineView>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QIcon>
#include <QDebug>

class WebView : public QWebEngineView
{
    Q_OBJECT
public:
    WebView(QWidget* parent = Q_NULLPTR);

public slots:
    void hotKeyShowOrHide();

protected:
    void closeEvent(QCloseEvent *);
    void hideEvent(QHideEvent *) ;
private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *minAction;
    QAction *maxAction;
    QAction *helpAction;
    QAction *quitAction;
};

#endif // WEBVIEW_H
