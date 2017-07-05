#include "readandprint.h"

ReadAndPrint::ReadAndPrint(QWidget *parent)
	: QMainWindow(parent), fileIndex(0), totalNumOfImgs(0)
{
	ui.setupUi(this);
	ui.processBtn->setDisabled(true);
	ui.nextImageBtn->setDisabled(true);
	ui.prevImageBtn->setDisabled(true);
}

ReadAndPrint::~ReadAndPrint()
{

}

void ReadAndPrint::on_openImageBtn_clicked() {
	imageNames.clear();
	
	imageNames = QFileDialog::getOpenFileNames(this, tr("Open Images"), ".", tr("Image files (*.png *.jpg *.jpeg *.bmp)"));

	QString fileName = imageNames.at(0);
	string imageName = fileName.toStdString();
	totalNumOfImgs = imageNames.size();
	Mat img = imread(imageName);
	Point p1, p2;

	p1.x = ui.posXTextBox->text().toInt();
	p1.y = ui.PosYTextBox->text().toInt();

	p2.x = ui.widthTextBox->text().toInt() + p1.x;
	p2.y = ui.heightTextBox->text().toInt() + p1.y;


	TextReadingAlgorithmController::getInstance()->setROI(p1, p2);

	TextReadingAlgorithmController::getInstance()->setImage(imageName);

	TextReadingAlgorithmController::getInstance()->getImage(img);

	cvtColor(img, img, CV_BGR2RGB);
	Size newSize = calculateNewImageSize(img);
	cv::resize(img, img, newSize);

	ui.processBtn->setDisabled(false);
	if (imageNames.size() > 1) {
		ui.nextImageBtn->setDisabled(false);
	}

	ui.numOfImages->setText(QString::number(fileIndex + 1)+ "/" +QString::number(totalNumOfImgs));
	ui.outputText->clear();
	ui.ImageViewer->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}

void ReadAndPrint::on_processBtn_clicked() {

	ui.ImageViewer->clear();

	TextReadingAlgorithmController::getInstance()->setThreshold(190);
	Mat processedImage;
	TextReadingAlgorithmController::getInstance()->process(processedImage);

	vector<string> sentences;

	TextReadingAlgorithmController::getInstance()->readText(sentences);

	for (auto s : sentences) {
		ui.outputText->appendPlainText(QString::fromStdString(s));
	}

	Size newSize = calculateNewImageSize(processedImage);
	cv::resize(processedImage, processedImage, newSize);

	ui.ImageViewer->setPixmap(QPixmap::fromImage(QImage(processedImage.data, processedImage.cols, processedImage.rows, processedImage.step, QImage::Format_Grayscale8)));
}

Size ReadAndPrint::calculateNewImageSize(const Mat&image) {

	QRect ivSize = ui.ImageViewer->geometry();

	int ivWidth = ivSize.width();
	int ivHeight = ivSize.height();

	int imgWidth = image.cols;
	int imgHeight = image.rows;

	double pixWidth = static_cast<double>(ivWidth) / imgWidth;
	double pixHeight = static_cast<double>(ivHeight) / imgHeight;

	double pixSize = min(pixHeight, pixWidth);

	int newImgWidth = pixSize * imgWidth;
	int newImgHeight = pixSize * imgHeight;

	return Size(newImgWidth, newImgHeight);
}

void ReadAndPrint::on_nextImageBtn_clicked() {

	if (fileIndex < imageNames.size() - 1) {
		fileIndex++;
		QString fileName = imageNames.at(fileIndex);
		string imageName = fileName.toStdString();

		Mat img = imread(imageName);

		TextReadingAlgorithmController::getInstance()->setImage(imageName);

		ui.numOfImages->setText(QString::number(fileIndex + 1) + "/" + QString::number(totalNumOfImgs));

		TextReadingAlgorithmController::getInstance()->getImage(img);

		cvtColor(img, img, CV_BGR2RGB);
		Size newSize = calculateNewImageSize(img);
		cv::resize(img, img, newSize);

		if (fileIndex > 0) {
			ui.prevImageBtn->setDisabled(false);
		}
		
		if (fileIndex == imageNames.size() - 1) {
			ui.nextImageBtn->setDisabled(true);
		}

		ui.outputText->clear();
		ui.ImageViewer->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
	}
}

void ReadAndPrint::on_prevImageBtn_clicked() {

	if (fileIndex > 0) {
		fileIndex--;
		QString fileName = imageNames.at(fileIndex);
		string imageName = fileName.toStdString();

		Mat img = imread(imageName);

		TextReadingAlgorithmController::getInstance()->setImage(imageName);

		ui.numOfImages->setText(QString::number(fileIndex + 1) + "/" + QString::number(totalNumOfImgs));

		TextReadingAlgorithmController::getInstance()->getImage(img);

		cvtColor(img, img, CV_BGR2RGB);
		Size newSize = calculateNewImageSize(img);
		cv::resize(img, img, newSize);

		if (fileIndex == 0) {
			ui.prevImageBtn->setDisabled(true);
		}

		ui.outputText->clear();
		ui.ImageViewer->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
	}
}