import cv2 as cv

#read image
img = cv.imread('images/cat.jpg')
cv.imshow('cat',img)

#read video
caputre = cv.VideoCapture(0)

cv.waitKey(0)