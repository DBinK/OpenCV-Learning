import cv2
import numpy as np

ori = cv2.imread('det_1.jpg')
im = cv2.imread("det_1.jpg", cv2.IMREAD_GRAYSCALE)

# 创建一个Blob检测器对象
detector = cv2.SimpleBlobDetector_create()

# 检测关键点
keypoints = detector.detect(im)

# 在图像上标记关键点
im_with_keypoints = cv2.drawKeypoints(im, keypoints, np.array([]), (0, 0, 255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

# 显示原始图像和带有关键点的图像
cv2.imshow('Original', ori)
cv2.imshow('BLOB', im_with_keypoints)
cv2.imwrite('BLOB.jpg', im_with_keypoints)

# 等待用户按下按键并检查是否为 Esc 键
if cv2.waitKey(0) & 0xff == 27:
    cv2.destroyAllWindows()