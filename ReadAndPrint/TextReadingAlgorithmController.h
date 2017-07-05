#pragma once
#include "TextReadingAlgorithm.h"
#include <qplaintextedit.h>

class TextReadingAlgorithmController
{
public:
	static TextReadingAlgorithmController* getInstance();
	void destroy();
	void setImage(const string& imageName);
	void getImage(Mat& img);
	void setThreshold(int th);
	void process(Mat& out);
	void readText(vector<string>& allSentences);
	void getTextContours(vector<vector<Point>>& contours);
	void setROI(const Point& p1, const Point& p2);

private:
	TextReadingAlgorithmController();
	static TextReadingAlgorithmController* singleton;
	TextReadingAlgorithm* trAlgorithm;
};

