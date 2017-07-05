/********************************************************************************
** Form generated from reading UI file 'readandprint.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READANDPRINT_H
#define UI_READANDPRINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReadAndPrintClass
{
public:
    QWidget *centralWidget;
    QLabel *ImageViewer;
    QPushButton *openImageBtn;
    QPushButton *processBtn;
    QPlainTextEdit *outputText;
    QPushButton *nextImageBtn;
    QPushButton *prevImageBtn;
    QLabel *numOfImages;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *posXTextBox;
    QLineEdit *PosYTextBox;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *widthTextBox;
    QLineEdit *heightTextBox;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ReadAndPrintClass)
    {
        if (ReadAndPrintClass->objectName().isEmpty())
            ReadAndPrintClass->setObjectName(QStringLiteral("ReadAndPrintClass"));
        ReadAndPrintClass->resize(1605, 809);
        centralWidget = new QWidget(ReadAndPrintClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ImageViewer = new QLabel(centralWidget);
        ImageViewer->setObjectName(QStringLiteral("ImageViewer"));
        ImageViewer->setGeometry(QRect(200, 20, 701, 721));
        ImageViewer->setAutoFillBackground(false);
        ImageViewer->setStyleSheet(QStringLiteral("background-color: rgb(40, 40, 40)"));
        ImageViewer->setTextFormat(Qt::AutoText);
        ImageViewer->setScaledContents(false);
        openImageBtn = new QPushButton(centralWidget);
        openImageBtn->setObjectName(QStringLiteral("openImageBtn"));
        openImageBtn->setGeometry(QRect(10, 30, 93, 28));
        processBtn = new QPushButton(centralWidget);
        processBtn->setObjectName(QStringLiteral("processBtn"));
        processBtn->setGeometry(QRect(10, 270, 93, 28));
        outputText = new QPlainTextEdit(centralWidget);
        outputText->setObjectName(QStringLiteral("outputText"));
        outputText->setGeometry(QRect(920, 20, 671, 721));
        nextImageBtn = new QPushButton(centralWidget);
        nextImageBtn->setObjectName(QStringLiteral("nextImageBtn"));
        nextImageBtn->setGeometry(QRect(580, 750, 81, 28));
        prevImageBtn = new QPushButton(centralWidget);
        prevImageBtn->setObjectName(QStringLiteral("prevImageBtn"));
        prevImageBtn->setGeometry(QRect(430, 750, 81, 28));
        numOfImages = new QLabel(centralWidget);
        numOfImages->setObjectName(QStringLiteral("numOfImages"));
        numOfImages->setGeometry(QRect(520, 750, 55, 21));
        numOfImages->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 171, 171));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 61, 21));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 61, 21));
        label_2->setAlignment(Qt::AlignCenter);
        posXTextBox = new QLineEdit(groupBox);
        posXTextBox->setObjectName(QStringLiteral("posXTextBox"));
        posXTextBox->setGeometry(QRect(80, 30, 81, 22));
        PosYTextBox = new QLineEdit(groupBox);
        PosYTextBox->setObjectName(QStringLiteral("PosYTextBox"));
        PosYTextBox->setGeometry(QRect(80, 60, 81, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(14, 100, 41, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(14, 130, 41, 20));
        widthTextBox = new QLineEdit(groupBox);
        widthTextBox->setObjectName(QStringLiteral("widthTextBox"));
        widthTextBox->setGeometry(QRect(80, 100, 81, 22));
        heightTextBox = new QLineEdit(groupBox);
        heightTextBox->setObjectName(QStringLiteral("heightTextBox"));
        heightTextBox->setGeometry(QRect(80, 130, 81, 22));
        ReadAndPrintClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ReadAndPrintClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ReadAndPrintClass->setStatusBar(statusBar);

        retranslateUi(ReadAndPrintClass);

        QMetaObject::connectSlotsByName(ReadAndPrintClass);
    } // setupUi

    void retranslateUi(QMainWindow *ReadAndPrintClass)
    {
        ReadAndPrintClass->setWindowTitle(QApplication::translate("ReadAndPrintClass", "ReadAndPrint", 0));
        ImageViewer->setText(QString());
        openImageBtn->setText(QApplication::translate("ReadAndPrintClass", "Open Image", 0));
        processBtn->setText(QApplication::translate("ReadAndPrintClass", "Process", 0));
        nextImageBtn->setText(QApplication::translate("ReadAndPrintClass", "Next", 0));
        prevImageBtn->setText(QApplication::translate("ReadAndPrintClass", "Previous", 0));
        numOfImages->setText(QString());
        groupBox->setTitle(QApplication::translate("ReadAndPrintClass", "Set Crop Region", 0));
        label->setText(QApplication::translate("ReadAndPrintClass", "Position X", 0));
        label_2->setText(QApplication::translate("ReadAndPrintClass", "Position Y", 0));
        posXTextBox->setText(QString());
        label_3->setText(QApplication::translate("ReadAndPrintClass", "Width", 0));
        label_4->setText(QApplication::translate("ReadAndPrintClass", "Height", 0));
    } // retranslateUi

};

namespace Ui {
    class ReadAndPrintClass: public Ui_ReadAndPrintClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READANDPRINT_H
