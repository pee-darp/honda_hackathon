import numpy as np
import cv2

cap = cv2.VideoCapture(1)
while(True):
    ret, img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

###Do your procecssing here###
    sift = cv2.SIFT()
    kp = sift.detect(gray,None)

    image = cv2.drawKeyPoints(gray,kp)


###Video frame processing ends###
    cv2.imshow('dst', image)
    delay = 1
    if cv2.waitKey(delay) & 0xff == 27:
        break
cap.release()
cv2.destroyAllWindows()
