import cv2
import numpy as np
import matplotlib.pyplot as plt

# %matplotlib inline

img = cv2.imread('burano.jpg')

# plt.imshow(img)

# Transform the image into HSV and HLS models

img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
img_hls = cv2.cvtColor(img, cv2.COLOR_BGR2HLS)

# Plot the converted images

fig, (ax1, ax2) = plt.subplots(nrows = 1, ncols =2, figsize = (20, 20))

ax1.imshow(img_hsv)
ax2.imshow(img_hls)
plt.show()