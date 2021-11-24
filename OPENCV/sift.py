#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 24 14:45:16 2021

@author: ledi
"""

#!/usr/bin/env python
# -*- coding=utf-8 -*-
# Summary: 使用OpenCV3.x-Python检测SIFT特征点
# Author:  Amusi
# Date:    2018-03-17
# Reference: https://docs.opencv.org/master/d5/d3c/classcv_1_1xfeatures2d_1_1SIFT.html
 
 
import cv2
import numpy
 
 
def main():
 
 
	img = cv2.imread("lena.png")
	cv2.imshow('Input Image', img)
	cv2.waitKey(0)
	
	# 检测
	sift = cv2.xfeatures2d.SIFT_create()
	keypoints = sift.detect(img, None)
	
	# 显示
	# 必须要先初始化img2
	img2 = img.copy()
	img2 = cv2.drawKeypoints(img, keypoints, img2, color=(0,255,0))
	cv2.imwrite('sift.png', img2)
	cv2.imshow('Detected SIFT keypoints', img2)
	cv2.waitKey(0)
    
if __name__ == '__main__':
	main()
 