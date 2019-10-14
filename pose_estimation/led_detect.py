import cv2
import numpy as np

#low_colour = cv2.scalar(0,0,10)
#high_colour = cv2.scalar(0,0,255)
cap = cv2.VideoCapture(1)
while (True):
    ret, frame = cap.read()
    #gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    mask = cv2.inRange(frame,(0,0,100),(80,80,255))
    mask_bgr = cv2.cvtColor(mask,cv2.COLOR_GRAY2BGR)
    clr_thresh = frame & mask_bgr
    gray = cv2.cvtColor(clr_thresh,cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray,(7,7),0)
    (T, threshImage) = cv2.threshold(blur, 90, 255, cv2.THRESH_BINARY)
    cv2.imshow('frame',threshImage)
    k = cv2.waitKey(1)
    if k == 27:
        break
cap.release
cv2.destroyAllWindows()
