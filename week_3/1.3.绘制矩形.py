import cv2
import numpy as np
import matplotlib.pyplot as plt

# %matplotlib inline

img = cv2.imread('burano.jpg')

# Copy the image

img_copy = img.copy()

# Draw a rectangle

cv2.rectangle(img_copy, pt1 = (320, 220), pt2 =(520, 350),

color = (255, 0, 0), thickness = 5)

img_rgb = cv2.cvtColor(img_copy, cv2.COLOR_BGR2RGB)

# plt.imshow(img_rgb)
plt.imshow(img_copy)