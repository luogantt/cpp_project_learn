#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 24 14:08:30 2021

@author: ledi
"""

#!/usr/bin/env python
# -*- coding=utf-8 -*-
# Summary: 使用OpenCV3.x-Python检测FAST特征点
# Author:  Amusi
# Date:    2018-03-17
# Reference: https://docs.opencv.org/master/df/d74/classcv_1_1FastFeatureDetector.html
 
import cv2
import numpy
 
def main():
 
	img = cv2.imread("lena.png")
	cv2.imshow('Input Image', img)
	cv2.waitKey(0)
 
	# 2018-03-17 Amusi: OpenCV3.x FeatureDetector写法有变化
	# OpenCV2.x
	# fast = cv2.FastFeatureDetector()
	# keypoints = fast.detect(img, None)
	
	# OpenCV3.x
	# 注意有_create()后缀
	fast = cv2.FastFeatureDetector_create()
	keypoints = fast.detect(img, None)
	
	# 必须要先初始化img2
	img2 = img.copy()
	img2 = cv2.drawKeypoints(img, keypoints, img2, color=(0,255,0))
	cv2.imwrite('fast.png', img2)
	cv2.imshow('Detected FAST keypoints', img2)
	cv2.waitKey(0)
    
if __name__ == '__main__':
	main()