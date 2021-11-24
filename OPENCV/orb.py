#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 24 14:18:07 2021

@author: ledi
"""

#!/usr/bin/env python
# -*- coding=utf-8 -*-
# Summary: 使用OpenCV3.x-Python检测ORB特征点
# Author:  Amusi
# Date:    2018-03-17
# Reference: https://docs.opencv.org/master/db/d95/classcv_1_1ORB.html
 
 
import cv2
import numpy
 
 
def main():
 
 
	img = cv2.imread("lena.png")
	cv2.imshow('Input Image', img)
	cv2.waitKey(0)
	
	# 检测
	orb = cv2.ORB_create()
	keypoints = orb.detect(img, None)
	
	# 显示
	# 必须要先初始化img2
	img2 = img.copy()
	img2 = cv2.drawKeypoints(img, keypoints, img2, color=(0,255,0))
	cv2.imwrite('orb.png', img2)
	cv2.imshow('Detected ORB keypoints', img2)
	cv2.waitKey(0)
    
if __name__ == '__main__':
	main()