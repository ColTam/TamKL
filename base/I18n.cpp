#include "I18n.h"

I18n::I18n(QObject *parent) : QObject(parent) {
    QTranslator *en = new QTranslator(this);
    QTranslator *cn = new QTranslator(this);
    bool ret = en->load("TamKL_en.qm");
    qWarning() << ret;
    ret = cn->load("TamKL_zh_CN.qm");
    qWarning() << ret;
    mTrans["en"] = en;
    mTrans["cn"] = cn;
}

void I18n::reTrans(const QString &lan) {
    if (mTrans.contains(lan)) {
        if (!mLastLan.isEmpty()) {
            QCoreApplication::removeTranslator(mTrans[mLastLan]);
        }
        mLastLan = lan;
        QCoreApplication::installTranslator(mTrans[mLastLan]);
        emit retransRequest();
        qWarning() << "retrans" << lan;
    }
}
