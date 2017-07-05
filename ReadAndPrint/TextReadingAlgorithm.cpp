#include "TextReadingAlgorithm.h"



TextReadingAlgorithm::TextReadingAlgorithm(): threshold(0)
{
	tessObj = new tesseract::TessBaseAPI();
	tessObj->Init("", "eng", tesseract::OEM_DEFAULT);
	tessObj->SetPageSegMode(static_cast<tesseract::PageSegMode>(7));
	cropRegion.x = 0;
	cropRegion.y = 0;
	cropRegion.width = 0;
	cropRegion.height = 0;
}


TextReadingAlgorithm::~TextReadingAlgorithm()
{
}

void TextReadingAlgorithm::setInputImage(const string& imageName){
	if (imageName.length() > 0) {
		inputImage = imread(imageName);
		Mat croppedImage = cropImage(inputImage);
		croppedImage.copyTo(inputImage);
		inputImage.copyTo(originalImage);
	}
	else {
		std::cout << "image loading failed" << std::endl;
	}
}

Mat TextReadingAlgorithm::processImage() {
	cvtColor(inputImage, outputImage, CV_BGR2GRAY);
	cv::threshold(outputImage, outputImage, threshold, 255, CV_THRESH_BINARY_INV);
	Mat img_contours;
	outputImage.copyTo(img_contours);
	findContours(img_contours, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	return outputImage;
}

void TextReadingAlgorithm::setThreshold(int t) {
	threshold = t;
}

vector<string> TextReadingAlgorithm::recognizeText() {
	createLineMask();
	sentenceDetection();
	return sentences;
}

vector<vector<Point>> TextReadingAlgorithm::getContours() const {
		return contours;
}

void TextReadingAlgorithm::setCropRegion(const Point& p1, const Point& p2) {
	int posOneX = p1.x;
	int posOneY = p1.y;

	int posTwoX = p2.x;
	int posTwoY = p2.y;

	int width = abs(posTwoX - posOneX);
	int height = abs(posTwoY - posOneY);

	cropRegion.x = posOneX;
	cropRegion.y = posOneY;

	cropRegion.width = width;
	cropRegion.height = height;
}

void TextReadingAlgorithm::createLineMask() {
	if (!contours.empty()) {
		Rect contRegion;
		int extend = 10;
		Point p1, p2;
		Mat processingImage;

		inputImage.copyTo(processingImage);

		for (auto contour : contours) {
			contRegion = boundingRect(Mat(contour).reshape(2));
			p1.x = contRegion.tl().x - extend;
			p1.y = contRegion.tl().y;

			p2.x = contRegion.br().x + extend;
			p2.y = contRegion.br().y;
			rectangle(processingImage, p1, p2, Scalar(0, 0, 0), CV_FILLED);
		}

		cvtColor(processingImage, sentenceMask, CV_BGR2GRAY);
		cv::threshold(sentenceMask, sentenceMask, 160, 255, CV_THRESH_BINARY_INV);
	}
		
}

void TextReadingAlgorithm::sentenceDetection() {

	Mat imageROI;
	findContours(sentenceMask, sentenceContours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	if (!sentenceContours.empty()) {

		sentences.clear();

		Rect sentenceBB;

		Point p1, p2;

		Mat phaseOneMask = Mat::zeros(inputImage.size(), CV_8UC1);

		Mat element = Mat(5, 5, CV_8U, Scalar(1));
		Mat closed;
		Size newImgROISize;

		for (int i = sentenceContours.size() - 1; i > 0; i--) {

			sentenceBB = boundingRect(Mat(sentenceContours[i]).reshape(2));

			p1.x = sentenceBB.tl().x;
			p1.y = sentenceBB.tl().y - 2;

			p2.x = sentenceBB.br().x;
			p2.y = sentenceBB.br().y + 2;

			if (abs(p1.y - p2.y) > 10) {
				imageROI = originalImage(Rect(p1, p2));

				Size imgROISize = imageROI.size();

				newImgROISize.width = (imgROISize.width * 5);
				newImgROISize.height = (imgROISize.height * 5);

				resize(imageROI, imageROI, newImgROISize);

				cvtColor(imageROI, imageROI, CV_BGR2GRAY);

				cv::threshold(imageROI, imageROI, 190, 255, CV_THRESH_BINARY);

				morphologyEx(imageROI, closed, MORPH_OPEN, element);

				tessObj->SetImage(imageROI.data, imageROI.size().width, imageROI.size().height, imageROI.channels(), imageROI.step1());
				tessObj->Recognize(0);

				const char* out = tessObj->GetUTF8Text();

				string sentence = out;

				string substring = sentence.substr(0, sentence.length() - 2);

				if (substring == "Can this question be improved?") {
				break;
				}
				sentences.push_back(substring);
				rectangle(originalImage, p1, p2, Scalar(255, 0, 0));
			}
		}
	}
}

Mat TextReadingAlgorithm::cropImage(Mat& imageToCrop) {
	return imageToCrop(cropRegion);
}