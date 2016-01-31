#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QStringList>
#include "ImageScene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow m_ui;
    QString m_currentImagePath;
    QStringList m_imageFileList;
    int m_currentImageIndex = -1;
    ImageScene m_imageScene;

    void updateImageView();

private slots:
	// Buttons
    void on_createPositiveFileButton_clicked();
    void on_createNegativeFileButton_clicked();

    void on_editVariablesButton_clicked();
    void on_genericButton_clicked();
    void on_allChannelsButton_clicked();

    void on_hueButton_clicked();
    void on_rButton_clicked();
    void on_gButton_clicked();
    void on_bButton_clicked();

    // Other controls
    void on_pathEdit_textChanged();
};

#endif // MAINWINDOW_H
