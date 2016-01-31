#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_imageScene()
{
    m_ui.setupUi(this);
    m_ui.graphicsView->setScene(&m_imageScene);
    updateImageView();
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateImageView()
{
    if (m_currentImageIndex >= 0)
    {
        m_imageScene.setImage(QImage(m_currentImagePath + "\\" + m_imageFileList[m_currentImageIndex]));
        m_ui.graphicsLabel->setText(
                    "Image " + QString::number(m_currentImageIndex + 1) +
                    " of " + QString::number(m_imageFileList.length()) +
                    ".  Filename: " + m_imageFileList[m_currentImageIndex]);
    }
    else
    {
        m_imageScene.setImage(QImage());
        m_ui.graphicsLabel->setText("No images found");
    }
}

// Button Slots

void MainWindow::on_createPositiveFileButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("MainWindow::on_createPositiveFileButton_clicked()");
    msgBox.exec();
}

void MainWindow::on_createNegativeFileButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("MainWindow::on_createNegativeFileButton_clicked()");
    msgBox.exec();
}


void MainWindow::on_editVariablesButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("MainWindow::on_editVariablesButton_clicked()");
    msgBox.exec();
}

void MainWindow::on_genericButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("MainWindow::on_genericButton_clicked()");
    msgBox.exec();
}

void MainWindow::on_allChannelsButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("MainWindow::on_allChannelsButton_clicked()");
    msgBox.exec();
}


void MainWindow::on_hueButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("MainWindow::on_hueButton_clicked()");
    msgBox.exec();
}

void MainWindow::on_rButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("MainWindow::on_rButton_clicked()");
    msgBox.exec();
}

void MainWindow::on_gButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("MainWindow::on_gButton_clicked()");
    msgBox.exec();
}

void MainWindow::on_bButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("MainWindow::on_bButton_clicked()");
    msgBox.exec();
}

// Other slots
void MainWindow::on_pathEdit_textChanged()
{
    m_imageFileList = QStringList();
    m_currentImageIndex = -1;
    m_currentImagePath = m_ui.pathEdit->text();
    updateImageView();
    if (m_currentImagePath.isEmpty())
        return;
    QDir dir(m_currentImagePath);

    if (dir.exists())
    {
        QStringList filters;
        filters << "*.bmp";
        filters << "*.png";

        m_imageFileList = dir.entryList(filters, QDir::Files | QDir::Readable, QDir::Name);
        m_currentImageIndex = (m_imageFileList.isEmpty() ? -1 : 0);
        updateImageView();
    }
}
