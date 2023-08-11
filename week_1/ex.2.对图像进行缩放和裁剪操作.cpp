/*
② 利用OpenCV进行图像的缩放和裁剪，并分别输出为
“robomaster3.jpg”， “robomaster4.jpg”讲讲以上图像变化的
区别
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 加载图像
    Mat img = imread("robomaster.jpg");

    // 缩放图像
    double scale_percent = 0.5; // 缩放比例为50%
    int width = int(img.cols * scale_percent);
    int height = int(img.rows * scale_percent);
    Size dim(width, height);
    Mat resized_img;
    resize(img, resized_img, dim, 0, 0, INTER_AREA);

    // 保存缩放后的图像
    imwrite("robomaster3.jpg", resized_img);

    // 裁剪图像
    Rect roi(200, 100, 300, 300); // 裁剪图像的区域为[200, 100, 300, 300]
    Mat cropped_img = img(roi);

    // 保存裁剪后的图像
    imwrite("robomaster4.jpg", cropped_img);

    // 显示原图、缩放后的图像和裁剪后的图像
    imshow("原图", img);
    imshow("缩放后的图像", resized_img);
    imshow("裁剪后的图像", cropped_img);

    return 0;
}

/*
代码2实现了对图像的缩放和裁剪操作，分别对应于resize和Mat的ROI操作。
缩放操作可以将图像按照指定的比例进行缩放，而裁剪操作则是将图像的指定区域截取出来。
缩放操作可以用于调整图像大小、提高处理速度，而裁剪操作可以用于提取图像中的特定区域，以便进行后续处理。
*/