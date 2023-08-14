import cv2
import numpy as np
import matplotlib.pyplot as plt

# %matplotlib inline

img = cv2.imread('burano.jpg')

# Copy the image

img_copy = img.copy()

# Draw a circle

cv2.circle(img_copy, center = (400, 80), radius =50,

color = (0, 0, 255), thickness = 5)

plt.imshow(img_copy)

img_rgb = cv2.cvtColor(img_copy, cv2.COLOR_BGR2RGB)

# plt.imshow(img_rgb)
plt.imshow(img_copy)