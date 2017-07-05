#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <tesseract\baseapi.h>
#include <allheaders.h>

using namespace cv;

class TextReadingAlgorithm
{
public:
	TextReadingAlgorithm();
	~TextReadingAlgorithm();
	void setInputImage(const string& imageName);
	Mat getInputImage() { return originalImage; }
	Mat processImage();
	void setThreshold(int t);
	vector<string> recognizeText();
	vector<vector<Point>> getContours() const;
	void setCropRegion(const Point& p1, const Point& p2);

private:
	Mat inputImage;
	Mat originalImage;
	Mat outputImage;
	Mat sentenceMask;
	int threshold;
	const char* outputText;
	tesseract::TessBaseAPI* tessObj;
	vector<vector<Point>> contours;
	vector<vector<Point>> sentenceContours;
	void createLineMask();
	void sentenceDetection();
	Mat cropImage(Mat& imageToCrop);
	vector<string> sentences;
	Rect cropRegion;
};

