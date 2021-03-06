#pragma once

#include <QMainWindow>

class AudioSignal;
class DenoisingWidget;
class AnalyzerWidget;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbShowSourceSignal_clicked();
    void on_pbRevert_clicked();
    void on_pbMakeWhiteNoise_clicked();

    void on_pbManualDenoising_clicked();
    void on_pbAutomaticDenoising_clicked();
    void on_pbAutomaticDenoisingTest_clicked();

    void on_actionRecorder_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();

private:
    void updatePlot();

    Ui::MainWindow *ui;
    QString m_fileName;

    QScopedPointer<AudioSignal> m_inputSignal;
    QScopedPointer<AudioSignal> m_processedSignal;
    QScopedPointer<DenoisingWidget> m_denoisingWidget;
    QScopedPointer<AnalyzerWidget> m_analyzerWidget;
};
