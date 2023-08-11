/* 
加载一张图像文件（"example.jpg"）并显示在名为"原始图像"的窗口中。
对原始图像进行边缘检测，将结果显示在名为"边缘图像"的窗口中。
*/

#include <opencv2/opencv.hpp> // 包含 OpenCV 库文件

using namespace cv; // 使用 OpenCV 命名空间

int main() {
    Mat image = imread("example.jpg"); // 加载图像文件到 Mat 对象中
    if (image.empty()) { // 如果图像为空（无法加载）
        std::cout << "无法加载图像文件." << std::endl; // 输出错误信息
        return -1; // 返回错误码
    }

    Mat edges; // 定义一个新的 Mat 对象 edges，用于存储边缘检测结果
    double threshold1 = 100.0; // 低阈值
    double threshold2 = 200.0; // 高阈值
    int apertureSize = 3; // Sobel 滤波器孔径大小

    Canny(image, edges, threshold1, threshold2, apertureSize); // 对原始图像进行边缘检测，将结果存储到 edges 中

    imshow("原始图像", image); 
    imshow("边缘图像", edges);
    imwrite("2.3.edges.jpg", edges); // 保存边缘图像

    waitKey(0); // 等待用户按下按键
    return 0; 
}



