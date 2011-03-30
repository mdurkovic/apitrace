#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QProcess>

class ApiTrace;
class ApiTraceFrame;
class ApiTraceModel;
class ApiTraceFilter;
class QLineEdit;
class QModelIndex;
class QProcess;
class QProgressBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

public slots:
    void loadTrace(const QString &fileName);

private slots:
    void callItemSelected(const QModelIndex &index);
    void openTrace();
    void filterTrace();
    void replayStart();
    void replayStop();
    void replayFinished();
    void replayError(QProcess::ProcessError err);
    void startedLoadingTrace();
    void finishedLoadingTrace();
    void lookupState();

private:
    void newTraceFile(const QString &fileName);
    void replayTrace(bool dumpState);

private:
    Ui_MainWindow m_ui;
    ApiTrace *m_trace;
    ApiTraceModel *m_model;
    ApiTraceFilter *m_proxyModel;
    QLineEdit *m_filterEdit;

    QProcess *m_replayProcess;

    QProgressBar *m_progressBar;

    QString m_traceFileName;

    ApiTraceFrame *m_currentFrame;
    bool m_findingState;
};


#endif