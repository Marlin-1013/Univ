import cv2

img1 = cv2.imread('test.jpg')
img2 = cv2.imread('test2.png')

img3 = cv2.hconcat([img1,img2])
img4 = cv2.resize(img3,(640,640))

height, width, channel = img4.shape

matrix = cv2.getRotationMatrix2D((width/2,height/2),45,0.7)
dst = cv2.warpAffine(img4, matrix, (width, height))

cv2.imshow("image",dst)
k = cv2.waitKey(0)
if k == 27:
	cv2.destroyAllWindows()
elif k == ord('s'):
	cv2.imwrite("test3.png",img3)
	cv2.destroyAllWindows()
