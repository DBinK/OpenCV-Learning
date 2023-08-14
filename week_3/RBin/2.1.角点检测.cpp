#include <opencv2/opencv.hpp>

int main() {
    // 读取图像
    cv::Mat img = cv::imread("chess_board.png");
    
    // 将图像转换为灰度图
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    
    // 将灰度图像转换为 float32 类型
    gray.convertTo(gray, CV_32F);
    
    // 进行角点检测
    cv::Mat dst;
    cv::cornerHarris(gray, dst, 9, 23, 0.04);
    
    // 查找最小和最大的角点响应值
    double minVal, maxVal;
    cv::minMaxLoc(dst, &minVal, &maxVal, nullptr, nullptr);
    
    // 克隆原始图像，用于绘制角点
    cv::Mat cornerImage = img.clone();
    
    for (int i = 0; i < dst.rows; ++i) {
        for (int j = 0; j < dst.cols; ++j) {
            // 如果角点响应值大于阈值，标记为红色
            if (dst.at<float>(i, j) > 0.01 * maxVal) {
                cv::circle(cornerImage, cv::Point(j, i), 5, cv::Scalar(0, 0, 255), 2);
            }
        }
    }
    
    // 使用阈值化来创建角点标记图像
    cv::Mat a;
    cv::threshold(dst, a, 0.01 * maxVal, 255, cv::THRESH_BINARY);
    
    // 将角点标记应用到原始图像上
    for (int i = 0; i < cornerImage.rows; ++i) {
        for (int j = 0; j < cornerImage.cols; ++j) {
            if (a.at<float>(i, j) == 255) {
                cornerImage.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 0, 255);
            }
        }
    }
    
    // 显示带有角点标记的图像
    while (true) {
        cv::imshow("corners", cornerImage);
        
        // 等待用户按下 'q' 键来退出循环
        if (cv::waitKey(120) & 0xff == 'q') {
            break;
        }
    }
    
    // 关闭所有窗口
    cv::destroyAllWindows();
    
    return 0;
}