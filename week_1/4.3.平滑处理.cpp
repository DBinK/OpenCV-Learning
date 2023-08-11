
#include <opencv2/opencv.hpp>  // 导入OpenCV库

int main() {
    cv::Mat image = cv::imread("example.jpg");  // 加载图像文件 example.jpg 到 Mat 对象 image 中
    if (image.empty()) {  // 检查图像是否加载成功
        std::cout << "无法加载图像文件." << std::endl;  // 输出错误信息
        return -1;  // 返回错误代码
    }

    cv::Mat blurredImage;  // 定义一个新的 Mat 对象 blurredImage，用于存储平滑后的图像
    cv::blur(image, blurredImage, cv::Size(5, 5));  // 对原始图像进行平滑处理，将结果存储到 blurredImage 中

    cv::imshow("原始图像", image);  // 显示原始图像
    cv::imshow("平滑图像", blurredImage);  // 显示平滑图像
    cv::waitKey(0);  // 等待用户按下键盘任意键

    return 0;  // 返回正常退出代码
}


/*

这段代码使用了 OpenCV 库来加载一张图像文件 example.jpg，并对该图像进行平滑处理，并将原始图像和平滑图像显示在屏幕上。

在 main 函数中，首先使用 imread 函数加载图像文件 example.jpg 到 Mat 对象 image 中。如果加载失败，则输出错误信息并返回错误代码。然后，定义一个新的 Mat 对象 blurredImage，用于存储平滑后的图像。接着，使用 blur 函数对原始图像进行平滑处理，并将结果存储到 blurredImage 中。blur 函数的第二个参数指定输出图像的 Mat 对象，第三个参数指定平滑处理的内核大小。

最后，使用 imshow 函数分别显示原始图像和平滑图像，并使用 waitKey 函数等待用户按下键盘任意键。当用户按下键盘时，程序正常退出并返回0。

需要注意的是，这段代码假设 example.jpg 文件位于当前工作目录下。如果实际情况不是这样，需要使用正确的文件路径来加载图像文件。

*/