//
//  Sort.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/12.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void swap(int* a, int* b);
void swap(long* a, long* b);
void InsertSort(int A[], int N);//插入排序
void SellSort(int A[], int N);//希尔排序
void Bubble(int A[], int N);//改进冒泡排序
void QSort(int A[], int begin, int end);//快速排序
int Partition(int A[], int begin, int end);
int HeapSort(long A[], int N);//堆排序
int Resore(long A[], int begin, int end);
void Msort(int A[], int B[], int N);//合并排序
void Merge(int A[], int abegin, int aend, int bend, int B[]);
void MPass(int A[], int N, int length, int B[]);



typedef int ElementType;
#define Max 9
class SQNode
{
public:
    ElementType Key;
};


class SQList
{
public:
    SQNode r[Max];
    int length;
};
void BinsertSort(ElementType A[], int N);//折半排序O(N^2),链表实现同理
void insert(int arr[], int temp[], int N);//2-路循环数组插入
void SelectSort(ElementType A[], int N);//选择排序
void Counting_Sort(int *arr, int n);//计数排序
//树形选择排序
//基数排序
//桶排序







#endif /* Sort_hpp */
