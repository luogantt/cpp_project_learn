#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec  8 09:46:29 2021

@author: ledi
"""


import numpy as np
import cv2
from matplotlib import pyplot as plt

def medianBlur(image,ksize=2,):
    '''
    中值滤波，去除椒盐噪声
    
    args:
        image：输入图片数据,要求为灰度图片
        ksize：滤波窗口大小        
    return：
        中值滤波之后的图片
    '''
    rows,cols = image.shape[:2]
    #输入校验
    half = ksize//2
    startSearchRow = half
    endSearchRow = rows-half-1
    startSearchCol = half
    endSearchCol = cols-half-1
    dst = np.zeros((rows,cols),dtype=np.uint8)
    #中值滤波
    for y in range(startSearchRow,endSearchRow):
        for x in range(startSearchCol,endSearchCol):
            window = []
            for i in range(y-half,y+half+1):
                for j in range(x-half,x+half+1):
                    window.append(image[i][j])
            #取中间值         
            window = np.sort(window,axis=None)                   
            if len(window)%2 == 1:            
                medianValue = window[len(window)//2]
            else:
                medianValue = int((window[len(window)//2]+window[len(window)//2+1])/2)
            dst[y][x] = medianValue
    return dst        
    

image = cv2.imread('/home/ledi/桌面/clion/learn_orbslam/cpp_project_learn/OPENCV/python_code/middle.png')


med=medianBlur(image)

cv2.imwrite('med.png',med)