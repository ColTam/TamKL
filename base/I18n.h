#ifndef I18N_H
#define I18N_H

#pragma once

#include <QObject>
#include <QTranslator>
#include <QMap>
#include <QCoreApplication>
#include <QDebug>
class I18n: public QObject{
    Q_OBJECT
public:
    I18n(QObject *parent = 0);
    Q_INVOKABLE void reTrans(const QString &lan);
signals:
    void retransRequest();
private:
    QMap<QString, QTranslator *> mTrans;
    QString mLastLan;
};

#endif // I18N_H
