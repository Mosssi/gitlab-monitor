#ifndef GITLAB_DESKTOP_MONITOR_LOGSERVICE_H
#define GITLAB_DESKTOP_MONITOR_LOGSERVICE_H

#include <QDebug>
#include <QtCore/QString>
#include <QtCore/QtMessageHandler>

class LogService {

public:
    static LogService &getInstance();

    void initializeService(bool logDebugLevel, bool logToFile, const QString &logFilePath = "/tmp/gitlab-monitor.log");
    static void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    [[nodiscard]] bool isLoggingToFile() const;
    FILE * getOutputStream();

private:
    bool logDebugLevel;
    bool logToFile;

    FILE * outputStream;
};


#endif //GITLAB_DESKTOP_MONITOR_LOGSERVICE_H
