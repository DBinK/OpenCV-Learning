	#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img1 = cv::imread("aa.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat img2 = cv::imread("bb.png", cv::IMREAD_GRAYSCALE);

    // 使用ORB特征检测器和描述符，计算关键点和描述符
    cv::Ptr<cv::ORB> orb = cv::ORB::create();
    std::vector<cv::KeyPoint> kp1, kp2;
    cv::Mat des1, des2;
    orb->detectAndCompute(img1, cv::noArray(), kp1, des1);
    orb->detectAndCompute(img2, cv::noArray(), kp2, des2);

    // 暴力匹配BFMatcher，遍历描述符，确定描述符是否匹配，然后计算匹配距离并排序
    cv::BFMatcher bf(cv::NORM_HAMMING, true);
    std::vector<cv::DMatch> matches;
    bf.match(des1, des2, matches);
    std::sort(matches.begin(), matches.end(), [](const cv::DMatch& m1, const cv::DMatch& m2) {
        return m1.distance < m2.distance;
    });

    // 使用cv::drawMatches将两个图像的匹配结果绘制出来
    cv::Mat img3;
    cv::drawMatches(img1, kp1, img2, kp2, matches, img3, cv::Scalar::all(-1), cv::Scalar::all(-1),
        std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    // 使用cv::imshow显示匹配结果
    cv::namedWindow("Matches", cv::WINDOW_NORMAL);
    cv::imshow("Matches", img3);
    cv::imwrite("Matches.jpg", img3);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}