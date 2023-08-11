#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // 读取两张图像
    Mat github_long = imread("github_long.jpg", IMREAD_GRAYSCALE);
    Mat github_short = imread("github_short.jpg", IMREAD_GRAYSCALE);

    // 创建 SIFT 特征检测器和描述符
    Ptr<SIFT> sift = SIFT::create();
    std::vector<KeyPoint> keypoints1, keypoints2;
    Mat descriptors1, descriptors2;

    // 检测关键点和计算描述符
    sift->detectAndCompute(github_long, noArray(), keypoints1, descriptors1);
    sift->detectAndCompute(github_short, noArray(), keypoints2, descriptors2);

    // 创建 BFMatcher 特征匹配器
    BFMatcher matcher(NORM_L2);
    std::vector<DMatch> matches;

    // 进行特征匹配
    matcher.match(descriptors1, descriptors2, matches);

    // 绘制匹配结果
    Mat matchImage;
    drawMatches(github_long, keypoints1, github_short, keypoints2, matches, matchImage);

    // 显示匹配结果
    namedWindow("Matches");
    imshow("Matches", matchImage);
    imwrite("2.5.matchImage.jpg", matchImage); // 保存边缘图像
    
    waitKey(0);

    return 0;
}