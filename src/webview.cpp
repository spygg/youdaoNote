#include "webview.h"
#include "helpdialog.h"

#include <QApplication>
#include <QCloseEvent>


WebView::WebView(QWidget* parent):
    QWebEngineView(parent),
    trayIcon(nullptr),
    trayIconMenu(nullptr),
    minAction(nullptr),
    maxAction(nullptr),
    helpAction(nullptr),
    quitAction(nullptr)
{
    trayIcon = new QSystemTrayIcon(this);
    connect(trayIcon, &QSystemTrayIcon::activated, this, &WebView::iconActivated);

    minAction = new QAction(tr("最小化"), this);
    connect(minAction, &QAction::triggered, this, &WebView::hide);

    maxAction = new QAction(tr("最大化"), this);
    connect(maxAction, &QAction::triggered, this, &WebView::showMaximized);

    helpAction = new QAction(tr("帮助"), this);
    connect(helpAction, &QAction::triggered, this, [=](){
        HelpDialog dlg;
        if(dlg.exec() == QDialog::Accepted){

        }
    });

    quitAction = new QAction(tr("退出"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minAction);
    trayIconMenu->addAction(maxAction);
    trayIconMenu->addAction(helpAction);
    trayIconMenu->addSeparator();

    trayIconMenu->addAction(quitAction);

    QIcon icon = QIcon(":/res/logo.png");
    trayIcon->setIcon(icon);
    setWindowIcon(icon);

    trayIcon->setToolTip("有道云笔记");
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
}

void WebView::closeEvent(QCloseEvent *e)
{
    hide();
    e->ignore();
}

void WebView::hideEvent(QHideEvent *e)
{
    hide();
    e->ignore();
}

void WebView::hotKeyShowOrHide()
{
    if(isHidden()){
        showMaximized();
    }
    else{
        hide();
    }
}


void WebView::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason) {
    case QSystemTrayIcon::DoubleClick:
        break;
    case QSystemTrayIcon::Trigger:{
        if(isHidden()){
            showMaximized();
        }
        else{
            hide();
        }
        break;
    }
    default:
        break;
    }
}

