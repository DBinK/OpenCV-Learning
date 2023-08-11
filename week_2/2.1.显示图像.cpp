#include <opencv2/opencv.hpp> // 包含 OpenCV 库文件

using namespace cv; // 使用 OpenCV 命名空间

int main() {
    Mat image = imread("example.jpg"); // 加载图像文件到 Mat 对象中
    if (image.empty()) { // 如果图像为空（无法加载）
        std::cout << "无法加载图像文件." << std::endl; // 输出错误信息
        return -1; // 返回错误码
    }

    Mat horizontalFlip; 
    Mat verticalFlip;   

    flip(image, horizontalFlip, 1); // 水平翻转
    flip(image, verticalFlip, 0); // 垂直翻转

    // imwrite("output_horizontal.jpg", horizontalFlip); // 保存水平翻转后的图片
    // imwrite("output_horizontal.jpg", verticalFlip); // 保存垂直翻转后的图片

    imshow("图像", image); // 在窗口中显示加载的图像
    imshow("图像", horizontalFlip); // 在窗口中显示水平翻转的图像
    imshow("图像", verticalFlip); // 在窗口中显示垂直翻转的图像

    waitKey(0); // 等待用户按下按键
    return 0; // 返回正常退出码
}




