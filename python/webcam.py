import cv2
frameWidth = 640
frameHeight = 480
cap = cv2.VideoCapture(0)
cap.set(3, frameWidth)
cap.set(4, frameHeight)
cap.set(10, 150)
while True:
	success, img = cap.read()
	src = cv2.flip(img, 1)
	cv2.imshow("Result", src)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break
