#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec  8 08:01:50 2021

@author: ledi
"""

# -*- coding: utf-8 -*-
"""
Created on Mon Aug 27 20:22:51 2018

@author: lenovo
"""
import numpy as np
import cv2
from matplotlib import pyplot as plt

'''
自己实现FAST角点检测算法:不依赖OpenCV库
参考代码：https://github.com/tbliu/FAST
'''
def rgb2gray(image):
    '''
    转换图片空间RGB->gray
    
    args:
        image：输入RGB图片数据        
    return：
        返回灰度图片
    '''
    rows,cols = image.shape[:2]
    grayscale = np.zeros((rows,cols),dtype=np.uint8)
    for row in range(0,rows):
        for col in range(0,cols):
            red,green,blue = image[row][col]
            gray = int(0.3*red+0.59*green+0.11*blue)
            grayscale[row][col] = gray
    return grayscale

def bgr2gray(image):
    '''
    转换图片空间BGR->gray
    
    args:
        image：输入BGR图片数据        
    return：
        返回灰度图片
    '''
    rows,cols = image.shape[:2]
    grayscale = image.copy()
    for row in range(0,rows):
        for col in range(0,cols):
            blue,green,red = image[row][col]
            gray = int(0.3*red+0.59*green+0.11*blue)
            grayscale[row][col] = gray
    return grayscale

def medianBlur(image,ksize=3,):
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
    
def circle(row,col):
    '''
    对于图片上一像素点位置(row,col)，获取其邻域圆上16个像素点坐标，圆由16个像素点组成
    
    args:
        row：行坐标 注意row要大于等于3
        col：列坐标 注意col要大于等于3       
    '''
    if row < 3 or col < 3:
        return
    point1 = (row-3, col)
    point2 = (row-3, col+1)
    point3 = (row-2, col+2)
    point4 = (row-1, col+3)
    point5 = (row, col+3)
    point6 = (row+1, col+3)
    point7 = (row+2, col+2)
    point8 = (row+3, col+1)
    point9 = (row+3, col)
    point10 = (row+3, col-1)
    point11 = (row+2, col-2)
    point12 = (row+1, col-3)
    point13 = (row, col-3)
    point14 = (row-1, col-3)
    point15 = (row-2, col-2)
    point16 = (row-3, col-1)
    
    return [point1, point2,point3,point4,point5,point6,point7,point8,point9,point10,point11,point12, point13,point14,point15,point16]

def is_corner(image,row,col,threshold):
    '''
    检测图像位置(row,col)处像素点是不是角点
    如果圆上有12个连续的点满足阈值条件，那么它就是一个角点
    
    方法：
        如果位置1和9它的像素值比阈值暗或比阈值亮，则检测位置5和位置15
        如果这些像素符合标准，请检查像素5和13是否相符
        如果满足有3个位置满足阈值条件，则它是一个角点
        重复循环函数返回的每个点如果没有满足阈值，则不是一个角落
        
        注意：这里我们简化了论文章中的角点检测过程，会造成一些误差
    
    args:
        image：输入图片数据,要求为灰度图片
        row：行坐标 注意row要大于等于3
        col：列坐标 注意col要大于等于3 
        threshold：阈值        
    return : 
        返回True或者False
    '''
    #校验
    rows,cols = image.shape[:2]
    if row < 3 or col < 3 :
        return False    
    if row >= rows-3 or col >= cols-3:
        return False    
    intensity = int(image[row][col])
    ROI = circle(row,col)
    #获取位置1,9,5,13的像素值
    row1, col1 = ROI[0]
    row9, col9 = ROI[8]
    row5, col5 = ROI[4]
    row13, col13 = ROI[12]
    intensity1 = int(image[row1][col1])
    intensity9 = int(image[row9][col9])
    intensity5 = int(image[row5][col5])
    intensity13 = int(image[row13][col13])
    #统计上面4个位置中满足  像素值  >  intensity + threshold点的个数
    countMore = 0
    #统计上面4个位置中满足 像素值  < intensity - threshold点的个数
    countLess = 0
    if intensity1 - intensity > threshold:
        countMore += 1 
    elif intensity1 + threshold < intensity:
        countLess += 1
    if intensity9 - intensity > threshold:
        countMore += 1
    elif intensity9 + threshold < intensity:
        countLess += 1
    if intensity5 - intensity > threshold:
        countMore += 1
    elif intensity5 + threshold < intensity:
        countLess += 1
    if intensity13 - intensity > threshold:
        countMore += 1
    elif intensity13 + threshold < intensity:
        countLess += 1
        
    return countMore >= 3 or countLess>=3

def areAdjacent(point1, point2):
    """
    通过欧拉距离来确定两个点是否相邻,如果它们在彼此的四个像素内，则两个点相邻
    
    args:
        point1:像素点1的位置
        point2:像素点2的位置
     return : 
        返回True或者False
    """
    row1, col1 = point1
    row2, col2 = point2
    xDist = row1 - row2
    yDist = col1 - col2
    return (xDist ** 2 + yDist ** 2) ** 0.5 <= 4

def calculateScore(image,point):
    """ 
    计算非极大值抑制的分数
    为每一个检测到的特征点计算它的响应大小，得分V定义为p和它周围16个像素点的绝对偏差之和
    考虑两个相邻的特征点，并比较它们的V,V值较小的点移除
    
    args:
        image：输入图片数据,要求为灰度图片
        point: 角点坐标
    """
    col, row  = point
    intensity = int(image[row][col])
    ROI = circle(row,col)
    values = []
    for p in ROI:
        values.append(int(image[p]))
    score = 0
    for value in values:
        score += abs(intensity - value)
    return score
    
def suppress(image, corners):
    '''
    Performs non-maximal suppression on the list of corners.
    For adjacent corners, discard the one with the smallest score.
    Otherwise do nothing

    Since we iterate through all the pixels in the image in order, any adjacent 
    corner points should be next to each other in the list of all corners

    Non-maximal suppression throws away adjacent corners which are the same point in real life
    
    args:
        image： is a numpy array of intensity values. NOTE: Image must be grayscale
        corners ： a list of (x,y) tuples   where x is the column index,and y is the row index
    '''
    i = 1
    #由于相邻的角点在corners列表中彼此相邻，所以我们写成下面形式
    while i < len(corners):
        currPoint = corners[i]
        prevPoint = corners[i - 1]
        #判断两个角点是否相邻
        if areAdjacent(prevPoint, currPoint):
            #计算非极大值抑制的分数
            currScore = calculateScore(image, currPoint)
            prevScore = calculateScore(image, prevPoint)
            #移除较小分数的点
            if (currScore > prevScore):
                del(corners[i - 1])
            else:
                del(corners[i])
        else:
            i += 1
            continue
    return


def detect(image, threshold=50,nonMaximalSuppress=True):
    '''
    corners = detect(image, threshold) performs the detection
    on the image and returns the corners as a list of (x,y) tuples
    where x is the column index, and y is the row index

    Nonmaximal suppression is implemented by default. 


    args： 
        image： is a numpy array of intensity values. NOTE: Image must be grayscale
        threshold：threshold is an int used to filter out non-corners. 
    return：
        returns the corners as a list of (x,y) tuples   where x is the column index,
        and y is the row index
    '''    
    corners = []
    rows,cols = image.shape[:2]
    #中值滤波
    image = medianBlur(image,3)
    cv2.imshow('medianBlur',image)   
    cv2.waitKey(20)
    #开始搜寻角点
    for row in range(rows):
        for col in range(cols):
            if is_corner(image, row, col, threshold):
                corners.append((col, row))  
    #非极大值抑制
    if nonMaximalSuppress:
        suppress(image, corners) 
    return corners;

def test():
    image = cv2.imread('/home/ledi/桌面/clion/learn_orbslam/cpp_project_learn/OPENCV/python_code/kaze.png')
    image = cv2.resize(image,dsize=(600,400))
    imgray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    corners = detect(imgray)
    print('检测到的角点个数为：',len(corners))     
    for point in corners:
        cv2.circle(image,point,1,(0,255,0),1)
    cv2.imshow('FAST',image)   
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
if __name__=='__main__':
    test()
