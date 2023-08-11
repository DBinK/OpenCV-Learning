/* 
加载一张图像文件（"example.jpg"）并显示在名为"原始图像"的窗口中。
对原始图像进行水平翻转和垂直翻转，并将翻转后的图像分别存储在全局变量horizontalFlip和verticalFlip中。

当用户在窗口中按下鼠标左键时，显示水平翻转后的图像在名为"水平翻转的图像"的窗口中。
当用户在窗口中按下鼠标右键时，显示垂直翻转后的图像在名为"垂直翻转的图像"的窗口中。

当用户移动鼠标时，在控制台输出鼠标当前位置的坐标。
*/

#include <opencv2/opencv.hpp> // 包含 OpenCV 库文件

using namespace cv; // 使用 OpenCV 命名空间

Mat horizontalFlip; //声明水平翻转的图像为全局变量
Mat verticalFlip;   //声明垂直翻转的图像为全局变量

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {   // 左键按下事件
        imshow("水平翻转的图像", horizontalFlip); // 在窗口中显示水平翻转的图像
    }
    else if (event == EVENT_RBUTTONDOWN)
    {   // 右键按下事件
        imshow("垂直翻转的图像", verticalFlip); // 在窗口中显示垂直翻转的图像

    }
    else if (event == EVENT_MOUSEMOVE)
    {
        std::cout << "Mouse moved to (" << x << ", " << y << ")" << std::endl;
    }
}

int main() {
    Mat image = imread("example.jpg"); // 加载图像文件到 Mat 对象中
    if (image.empty()) { // 如果图像为空（无法加载）
        std::cout << "无法加载图像文件." << std::endl; // 输出错误信息
        return -1; // 返回错误码
    }

    flip(image, horizontalFlip, 1); // 水平翻转
    flip(image, verticalFlip, 0); // 垂直翻转

    imshow("原始图像", image); // 在窗口中显示加载的图像
 
    setMouseCallback("原始图像", onMouse, nullptr);

    waitKey(0); // 等待用户按下按键
    return 0; 
}



