import cv2
import numpy as np

img=cv2.imread("test.jpg")
img_hsv=cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

def find_brown_part(img_hsv):
    lower_red = np.array([0,50,50])
    upper_red = np.array([10,255,255])
    mask0 = cv2.inRange(img_hsv, lower_red, upper_red)

    # upper mask (170-180)
    lower_red = np.array([170,50,50])
    upper_red = np.array([180,255,255])
    mask1 = cv2.inRange(img_hsv, lower_red, upper_red)

    # join my masks
    mask = mask0+mask1

    # set my output img to zero everywhere except my mask
    output_img = img.copy()
    output_img[np.where(mask==0)] = 0
    return output_img

output_img=find_red_part(img_hsv)

cv2.imshow("red image",output_img)
cv2.waitKey(0)
cv2.destroyAllWindows()