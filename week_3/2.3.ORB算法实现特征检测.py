import numpy as np
import cv2
from matplotlib import pyplot as plt

# 读取图片内容
img1 = cv2.imread('aa.jpg', 0)
img2 = cv2.imread('bb.png', 0)

# 使用ORB特征检测器和描述符，计算关键点和描述符
orb = cv2.ORB_create()
kp1, des1 = orb.detectAndCompute(img1, None)
kp2, des2 = orb.detectAndCompute(img2, None)

# 暴力匹配BFMatcher，遍历描述符，确定描述符是否匹配，然后计算匹配距离并排序
bf = cv2.BFMatcher(normType=cv2.NORM_HAMMING, crossCheck=True)
matches = bf.match(des1, des2)
matches = sorted(matches, key=lambda x: x.distance)

# 使用plt将两个图像的匹配结果显示出来
img3 = cv2.drawMatches(img1, kp1, img2, kp2, matches, outImg=img2, flags=2)
plt.imshow(img3)
plt.show()