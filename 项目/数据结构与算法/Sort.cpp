//
//  Sort.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/12.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "Sort.hpp"
void swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void swap(long* a, long* b)
{
    long temp=*a;
    *a=*b;
    *b=temp;
}
void InsertSort(int A[], int N)
{
    for(int i=1; i<N; ++i)
    {
        int temp=A[i];
        int j=i-1;
        while(j>=0&&A[j]>A[i])
        {
            A[j+1]=A[j];
            --j;
        }
        A[j+1]=temp;
    }
}
void SellSort(int A[], int N)
{
    int d=N/2;
    while(d>0)
    {
        for(int i=d; i<N; ++i)
        {
            int temp=A[i];
            int j=i-d;
            while(j>=0&&A[j+d]<A[j])
            {
                A[j+d]=A[j];
                j-=d;
            }
            A[j+d]=temp;
        }
        d/=2;
    }
}
void Bubble(int A[], int N)
{
    int Bound=N;
    int t;//记录每次冒泡的边界
    while(Bound!=0)
    {
        t=0;
        for(int i=1; i<Bound; ++i)
        {
            if(A[i-1]>A[i])
            {
                t=i;
                swap(&A[i], &A[i-1]);
            }
        }
        Bound=t;
    }
}
void QSort(int A[], int begin, int end)
{
    if(begin<end)
    {
        int j=Partition(A, begin, end);
        QSort(A, begin, j-1);
        QSort(A, j+1, end);
    }
}
int Partition(int A[], int begin, int end)
{
    int i=begin+1;
    int j=end+1;
    while(i<j)
    {
        while(A[i]<=A[begin])
            ++i;
        --j;
        while(A[j]>A[begin])
            --j;
        if(i<j)
            swap(&A[i], &A[j]);
    }
    swap(&A[begin], &A[j]);
    return j;
}
int HeapSort(long A[], int N)
{
    int time=0;
    for(int i=N/2-1; i>=0; --i)
        time+=Resore(A, i, N-1);
    for(int i=N-1; i>0; --i)
    {
        swap(&A[0], &A[i]);
        time+=Resore(A, 0, i);
    }
    return time;
}
int Resore(long A[], int begin, int end)
{
    int time=0;
    int i=begin;
    int m;
    while(i<=end/2-1)
    {
        if(2*i<end&&A[2*i]<A[2*i+1])
        {
            m=2*i+1;
            ++time;
        }
        else
            m=2*i;
        if(A[i]<A[m])
        {
            ++time;
            swap(&A[i], &A[m]);
            i=m;
        }
        else
            i=end;
    }
    return time;
}
void Msort(int A[], int B[], int N)
{
    int L=1;
    while(L<N)
    {
        MPass(A, N, L, B);
        L*=2;
        MPass(B, N, L, A);
        L*=2;
    }
}
void MPass(int A[], int N, int length, int B[])
{
    int i=0;
    while(i+2*length-1<=N)
    {
        Merge(A, i, i+length-1, i+2*length-1, B);
        i+=2*length;
    }
    if(i+length-1<N)
        Merge(A, i, i+length-1, N, B);
    else
        for(; i<N; ++i)
            B[i]=A[i];
}
void Merge(int A[], int abegin, int aend, int bend, int B[])
{
    int i=abegin;
    int j=aend+1;
    int k=abegin;
    while(i<=aend&&j<=bend)
    {
        if(A[i]<A[j])
            B[k]=A[i++];
        else
            B[k]=A[j++];
        ++k;
    }
    while(i<=aend)
        B[k++]=A[i++];
    while(j<=bend)
        B[k++]=A[j++];
}



void BinsertSort(ElementType A[], int N)
{
    int low, mid, high;
    int i, j;
    ElementType Temp;
    for(i=1; i<N; ++i)
    {
        low=0;
        high=i-1;
        mid=(low+high)/2;
        Temp=A[i];
        while(low<=high)//不明白为啥等于
        {
            if(A[mid]>Temp)
            {
                high=mid-1;
                mid=(low+high)/2;
            }
            else
            {
                low=mid+1;
                mid=(low+high)/2;
            }
        }
        for(j=i; j>low; --j)
        {
            A[j]=A[j-1];
        }
        A[low]=Temp;
    }
}
void insert(int arr[], int temp[], int N)
{
    int i, first, finall, k;
    first=finall=0;
    temp[0]=arr[0];
    for(i=1; i<N; ++i)
    {
        if(arr[i]>temp[finall])//比末尾大
        {
            finall=(finall+1+N)%N;
            temp[finall]=arr[i];
        }
        else if(arr[i]<temp[first])//比开头小
        {
            first=(first-1+N)%N;
            temp[first]=arr[i];
        }
        else//比开头大比末尾小
        {
            k=(finall+1+N)%N;
            while(arr[i]<temp[(k-1+N)%N])
            {
                temp[k]=temp[(k-1+N)%N];
                k=(k-1+N)%N;
            }
            temp[k]=arr[i];
            finall=(finall+1+N)%N;
        }
    }
    for(i=0; i<N; ++i)
    {
        arr[i]=temp[i];
        cout<<arr[i];
    }
    
}
void SelectSort(ElementType A[], int N)
{
    int i, j, Min, Temp;
    for(i=0; i<N-1; ++i)
    {
        Min=0;
        for(j=i+1; j<N; ++j)
            if(A[Min]>A[j])
                Min=j;
        Temp=A[i];
        A[i]=A[j];
        A[j]=Temp;
    }
}



void Counting_Sort(int *arr, int n)
{
    int *count_arr = (int *)malloc(sizeof(int) * 100);
    int i, j, l=0;
    //初始化计数数组
    for(i = 0; i<100; i++)
        count_arr[i] = 0;
    //统计i的次数
    for(i = 0;i<n;i++)
        count_arr[arr[i]]++;
    //对所有的计数累加
    for(i=0; i<100; ++i)
        for(j=0; j<count_arr[i]; ++j)
            arr[l++]=i;
}
