import numpy as np
import cv2

#Read an image
img = cv2.imread('mcard.jpg', 0)
print(np.shape(img))
#Display an image
cv2.imshow('mcard', img)
k = cv2.waitKey(0)
if k == 27:
    cv2.destroyAllWindows()
elif k == ord('s'):
#Saving an image
    cv2.imwrite('mcard.png',img)
    cv2.destroyAllWindows()
