#include <opencv2/opencv.hpp>

int main() {
    // 读取原始图像,将图像转换为灰度图
    cv::Mat ori = cv::imread("det_1.jpg");
    cv::Mat im = cv::imread("det_1.jpg", cv::IMREAD_GRAYSCALE);

    // 创建Blob检测器对象
    cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create();

    // 检测关键点
    std::vector<cv::KeyPoint> keypoints;
    detector->detect(im, keypoints);

    // 在图像上标记关键点
    cv::Mat im_with_keypoints;
    cv::drawKeypoints(im, keypoints, im_with_keypoints, cv::Scalar(0, 0, 255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    // 显示原始图像和带有关键点的图像
    cv::imshow("Original", ori);
    cv::imshow("BLOB", im_with_keypoints);

    // 等待用户按下按键并检查是否为 Esc 键
    if (cv::waitKey(0) == 27) {
        cv::destroyAllWindows();
    }

    return 0;
}