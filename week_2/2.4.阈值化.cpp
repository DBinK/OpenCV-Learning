/* 
加载一张图像文件（"example.jpg"）并显示在名为"原始图像"的窗口中。
对原始图像进行阈值化，将结果显示在名为"阈值化图像"的窗口中。
*/

#include <opencv2/opencv.hpp> // 包含 OpenCV 库文件

using namespace cv; // 使用 OpenCV 命名空间

int main() {
    Mat image = imread("example.jpg"); // 加载图像文件到 Mat 对象中
    if (image.empty()) { // 如果图像为空（无法加载）
        std::cout << "无法加载图像文件." << std::endl; // 输出错误信息
        return -1; // 返回错误码
    }

    Mat thresholded;
    double thresh = 128.0; // 阈值
    double maxval = 255.0; // 最大值
    int type = cv::THRESH_BINARY; // 阈值化类型

    threshold(image, thresholded, thresh, maxval, type);

    imshow("原始图像", image);
    imshow("阈值化图像", thresholded);

    waitKey(0); // 等待用户按下按键
    return 0; 
}