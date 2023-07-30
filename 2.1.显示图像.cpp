#include <opencv2/opencv.hpp> // 包含 OpenCV 库文件

using namespace cv; // 使用 OpenCV 命名空间

int main() {
    Mat image = imread("example.jpg"); // 加载图像文件到 Mat 对象中
    if (image.empty()) { // 如果图像为空（无法加载）
        std::cout << "无法加载图像文件." << std::endl; // 输出错误信息
        return -1; // 返回错误码
    }
    imshow("图像", image); // 在窗口中显示加载的图像
    waitKey(0); // 等待用户按下按键
    return 0; // 返回正常退出码
}