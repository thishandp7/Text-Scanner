#include "TextReadingAlgorithmController.h"

TextReadingAlgorithmController* TextReadingAlgorithmController::singleton = nullptr;

TextReadingAlgorithmController::TextReadingAlgorithmController()
{
	trAlgorithm = new TextReadingAlgorithm();
}

TextReadingAlgorithmController* TextReadingAlgorithmController::getInstance() {
	if (singleton == nullptr) {
		singleton = new TextReadingAlgorithmController();
		return singleton;
	}
	else {
		return singleton;
	}
}

void TextReadingAlgorithmController::destroy() {
	if (singleton != nullptr) {
		delete singleton;
		singleton = nullptr;
	}
}

void TextReadingAlgorithmController::setImage(const string& imageName) {
	trAlgorithm->setInputImage(imageName);
}

void TextReadingAlgorithmController::getImage(Mat& img) {
	img = trAlgorithm->getInputImage();
}

void TextReadingAlgorithmController::setThreshold(int th) {
	trAlgorithm->setThreshold(th);
}

void TextReadingAlgorithmController::process(Mat& out) {
	out = trAlgorithm->processImage();
}

void TextReadingAlgorithmController::readText(vector<string>& allSentences) {
	allSentences = trAlgorithm->recognizeText();
}

void TextReadingAlgorithmController::getTextContours(vector<vector<Point>>& contours) {
	contours = trAlgorithm->getContours();
}

void TextReadingAlgorithmController::setROI(const Point& p1, const Point& p2) {
	trAlgorithm->setCropRegion(p1, p2);
}