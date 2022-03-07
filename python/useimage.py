import cv2
import numpy as np

img = cv2.imread("image/lena.png", cv2.IMREAD_GRAYSCALE)
#kernel = np.ones((5,5),np.uint8)

#imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
#imgBlur = cv2.GaussianBlur(imgGray,(7,7),0)
#imgCanny = cv2.Canny(img,150,200)
#imgDialation = cv2.dilate(imgCanny,kernel,iterations=1)
#imgEroded = cv2.erode(imgDialation,kernel,iterations=1)

#cv2.imshow("Gray Image",imgGray)
#cv2.imshow("Blur Image",imgBlur)
#cv2.imshow("Canny Image",imgCanny)
#cv2.imshow("Dialation Image",imgDialation)
#cv2.imshow("Eroded Image",imgEroded)

k = cv2.getStructuringElement(cv2.MORPH_RECT, (3,3))
gradient = cv2.morphologyEx(img, cv2.MORPH_GRADIENT, k)
opening =  cv2.morphologyEx(img, cv2.MORPH_OPEN, k)
closing =  cv2.morphologyEx(img, cv2.MORPH_CLOSE, k)

merged = np.hstack((img, gradient))
merged2 = np.hstack((opening, closing))
merged3 = np.vstack((merged, merged2))
cv2.imshow("gradient", merged3)

cv2.waitKey(0)
