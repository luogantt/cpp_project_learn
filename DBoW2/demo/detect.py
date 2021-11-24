#!/usr/bin/env python
# -*- coding=utf-8 -*-
# Summary: 使用OpenCV3.x-Python检测AKAZE特征点
# Author:  Amusi
# Date:    2018-03-17
# Reference: https://docs.opencv.org/master/d8/d30/classcv_1_1AKAZE.html
 
import cv2
import numpy
 
def main():
 
	img = cv2.imread("lg.jpg")
	cv2.imshow('Input Image', img)
	cv2.waitKey(0)
	
	# 检测
	akaze = cv2.AKAZE_create()
	keypoints = akaze.detect(img, None)
	
	# 显示
	# 必须要先初始化img2
	img2 = img.copy()
	img2 = cv2.drawKeypoints(img, keypoints, img2, color=(0,255,0))
	cv2.imshow('Detected AKAZE keypoints', img2)
	cv2.waitKey(0)
    
if __name__ == '__main__':
	main()
