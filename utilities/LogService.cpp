#include "LogService.h"

#include <QString>
#include <QByteArray>
#include <QtCore/QTime>
#include <QtCore/QElapsedTimer>

LogService &LogService::getInstance() {

    static LogService instance;
    return instance;
}

void LogService::initializeService(bool logDebugLevel, bool logToFile, const QString &logFilePath) {

    this->logDebugLevel = logDebugLevel;
    this->logToFile = logToFile;

    if (logToFile) {
        outputStream = fopen(logFilePath.toLocal8Bit().constData(), "a");
        if (outputStream == nullptr) {
            outputStream = stdout;
        }
    } else {
        outputStream = stdout;
    }

    qInstallMessageHandler(LogService::myMessageOutput);
}

void LogService::myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QByteArray localMsg = msg.toLocal8Bit().constData();
    const char * currentDateTime = QDateTime::currentDateTime().toString("yyyy MMM dd HH:mm:ss.zzz").toLocal8Bit().constData();
    switch (type) {
        case QtDebugMsg:
            if (LogService::getInstance().logDebugLevel) {
                fprintf(LogService::getInstance().getOutputStream(), "[%s] - [ Debug  ] - %s\n", currentDateTime, localMsg.constData());
            }
            break;
        case QtInfoMsg:
            fprintf(LogService::getInstance().getOutputStream(), "[%s] - [  Info  ] - %s\n", currentDateTime, localMsg.constData());
            break;
        case QtWarningMsg:
            fprintf(LogService::getInstance().getOutputStream(), "[%s] - [Warning ] - %s\n", currentDateTime, localMsg.constData());
            break;
        case QtCriticalMsg:
            fprintf(LogService::getInstance().getOutputStream(), "[%s] - [Critical] - %s\n", currentDateTime, localMsg.constData());
            break;
        case QtFatalMsg:
            fprintf(LogService::getInstance().getOutputStream(), "[%s] - [ Fatal  ] - %s\n", currentDateTime, localMsg.constData());
            break;
    }
    if (LogService::getInstance().isLoggingToFile()) {
        fflush(LogService::getInstance().getOutputStream());
    }
}

FILE * LogService::getOutputStream() {

    return outputStream;
}

bool LogService::isLoggingToFile() const {

    return logToFile;
}
