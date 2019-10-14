import numpy as np
import cv2

cap = cv2.VideoCapture(0)
while(True):
    ret, frame = cap.read()
    #gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    cv2.imshow('frame', frame)
    delay = 100
    k = cv2.waitKey(delay)
    print('fps:',1000/delay)
    if k == 27:
        break
cap.release()
cv2.destroyAllWindows()
