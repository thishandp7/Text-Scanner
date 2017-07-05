#ifndef READANDPRINT_H
#define READANDPRINT_H

#include <QtWidgets/QMainWindow>
#include "ui_readandprint.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <qfiledialog.h>
#include <iostream>
#include <TextReadingAlgorithmController.h>

using namespace cv;

class ReadAndPrint : public QMainWindow
{
	Q_OBJECT

public:
	ReadAndPrint(QWidget *parent = 0);
	~ReadAndPrint();

private slots:
	void on_openImageBtn_clicked();
	void on_processBtn_clicked();
	void on_nextImageBtn_clicked();
	void on_prevImageBtn_clicked();

private:
	Ui::ReadAndPrintClass ui;
	Size calculateNewImageSize(const Mat&image);
	QStringList imageNames;
	int fileIndex;
	int totalNumOfImgs;
};

#endif // READANDPRINT_H
