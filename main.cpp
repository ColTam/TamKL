#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QQmlContext>
#include <QTranslator>

#include "base/I18n.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TamKL_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }
    I18n i18n;
    QQmlApplicationEngine engine;
    QObject::connect(&i18n, &I18n::retransRequest, &engine, &QQmlApplicationEngine::retranslate);

    engine.rootContext()->setContextProperty("i18n", &i18n);
    const QUrl url(u"qrc:/TamKL/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
