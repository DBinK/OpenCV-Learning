#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    Mat image = imread("example.jpg");
    if (image.empty()) {
        std::cout << "无法加载图像文件." << std::endl;
        return -1;
    }
    imshow("图像", image);
    waitKey(0);
    return 0;
}