/*
① 利用OpenCV进行图像的膨胀和腐蚀操作，并分别输出为
“robomaster1.jpg”， “robomaster2.jpg”讲讲以上图像变化的
区别。
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
    // 读入原图
    Mat image = imread("robomaster.jpg", IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cout << "无法加载图像文件." << std::endl;
        return -1;
    }

    // 定义膨胀和腐蚀的内核大小
    int kernel_size = 3;

    // 定义膨胀和腐蚀操作的迭代次数
    int iterations = 1;

    // 定义膨胀和腐蚀操作后的图像
    Mat dilatedImage, erodedImage;

    // 定义膨胀和腐蚀的内核
    Mat element = getStructuringElement(MORPH_RECT, Size(kernel_size, kernel_size));

    // 对原图进行膨胀操作
    dilate(image, dilatedImage, element, Point(-1, -1), iterations);

    // 对原图进行腐蚀操作
    erode(image, erodedImage, element, Point(-1, -1), iterations);

    // 显示原图、膨胀和腐蚀后的图像
    imshow("原图", image);
    imshow("膨胀后的图像", dilatedImage);
    imshow("腐蚀后的图像", erodedImage);

    // 保存膨胀和腐蚀后的图像
    imwrite("robomaster1.jpg", dilatedImage);
    imwrite("robomaster2.jpg", erodedImage);

    waitKey(0);

    return 0;
}

/*
代码1实现了对图像的膨胀和腐蚀操作，分别对应于dilate和erode函数。
膨胀操作可以使图像中的白色区域扩张，黑色区域缩小，而腐蚀操作则相反，可以使白色区域缩小，黑色区域扩张。
这两种操作可以用于去除噪声、填充空洞等。
*/