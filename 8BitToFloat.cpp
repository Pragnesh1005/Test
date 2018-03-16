// Convert 8 bit image to float image using opencv
// Test project 
#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

int main ()
{
    char *buffer = new char [300*300*3];

    FILE *iFptr = fopen ("dog.raw", "rb");
    fread (buffer, 1, 300*300*3, iFptr);
    fclose(iFptr);

    cv::Mat rgbMat(300, 300, CV_8UC1, buffer);

    // Convert to a float matrix needed by SNPE
    cv::Mat rgbFloatMat;
    rgbFloatMat.convertTo(rgbFloatMat, CV_32F);

    FILE *fptr = fopen ("out_float.rgb", "wb");
    fwrite(rgbFloatMat.data, 1, (rgbFloatMat.rows*rgbFloatMat.cols*3), fptr);
    fclose (fptr);
    return 0;
}
