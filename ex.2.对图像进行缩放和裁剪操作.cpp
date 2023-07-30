/*
② 利用OpenCV进行图像的缩放和裁剪，并分别输出为
“robomaster3.jpg”， “robomaster4.jpg”讲讲以上图像变化的
区别
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
    // 读入原图
    Mat image = imread("robomaster.jpg");
    if (image.empty()) {
        std::cout << "无法加载图像文件." << std::endl;
        return -1;
    }

    // 定义缩放比例
    double scale = 0.5;

    // 定义裁剪区域
    Rect roi(200, 200, 400, 400);

    // 定义缩放后的图像和裁剪后的图像
    Mat scaledImage, croppedImage;

    // 缩放图像
    resize(image, scaledImage, Size(), scale, scale);

    // 裁剪图像
    croppedImage = image(roi);

    // 显示原图、缩放后的图像和裁剪后的图像
    imshow("原图", image);
    imshow("缩放后的图像", scaledImage);
    imshow("裁剪后的图像", croppedImage);

    // 保存缩放后的图像和裁剪后的图像
    imwrite("robomaster3.jpg", scaledImage);
    imwrite("robomaster4.jpg", croppedImage);

    waitKey(0);

    return 0;
}

/*
代码2实现了对图像的缩放和裁剪操作，分别对应于resize和Mat的ROI操作。
缩放操作可以将图像按照指定的比例进行缩放，而裁剪操作则是将图像的指定区域截取出来。
缩放操作可以用于调整图像大小、提高处理速度，而裁剪操作可以用于提取图像中的特定区域，以便进行后续处理。
*/