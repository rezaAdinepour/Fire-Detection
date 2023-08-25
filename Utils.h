#ifndef UTILS_H
#define UTILS_H

#include <opencv.hpp>
#include <atlimage.h>
#include <fstream>

using namespace cv;

bool Mat2CImage(Mat& mat, CImage& img)
{
	if (mat.empty()) {
		return false;
	}

	if (!img.IsNull()) {
		img.Destroy();
	}

	int nBPP = mat.channels() * 8;

	img.Create(mat.cols, mat.rows, nBPP);

	if (nBPP == 8) {
		static RGBQUAD pRGB[256];

		for (int i = 0; i < 256; i++) {
			pRGB[i].rgbBlue = pRGB[i].rgbGreen = pRGB[i].rgbRed = i;
		}

		img.SetColorTable(0, 256, pRGB);
	}

	uchar* psrc = mat.data;
	uchar* pdst = (uchar*)img.GetBits();

	int imgPitch = img.GetPitch();

	for (int y = 0; y < mat.rows; y++) {
		memcpy(pdst, psrc, mat.cols * mat.channels());

		psrc += mat.step;
		pdst += imgPitch;
	}

	return true;
}

#endif

