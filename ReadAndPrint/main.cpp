#include "readandprint.h"
#include <QtWidgets/QApplication>
#include "TextReadingAlgorithm.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ReadAndPrint w;
	w.setFixedSize(w.size());
	w.show();
	return a.exec();
}
