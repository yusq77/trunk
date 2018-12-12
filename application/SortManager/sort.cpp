/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-12-11 10:10:15
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unionlog.h"
#include "sort.h"


/* quote swap */
void swap_quote(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
/* point swap */
void swap_pointer(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
/* cannot swap*/
void swap_qp(int *(&x), int *(&y))
{
    int *temp = x;
    x = y;
    y = temp;
}
/* print arr */
void printArr(int *arr, int n)
{
    int i = 0;

    for(i=0; i<n; i++)
    {
        UnionLogErr("%d", arr[i]);
    }
    UnionLogErr("\n");
}
/* bubble sort */
void bubbleSort(int *arr, int n)
{
    int i, j;
    bool isSorted = false;

    for(i=0; i<n-1; i++)
    {
        isSorted = false;
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap_pointer(&arr[j], &arr[j+1]);
                isSorted = true;
            }
        }

        if(!isSorted) //do nothing
            return;
    }
}
/* cocktailSort: bubbleSort improve */
void cocktailSort(int *arr, int n)
{
    int left = 0, right = n-1;
    bool isSorted = false;

    while(left<right)
    {
        isSorted = false;
        for(int i=left; i<right; i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap_pointer(&arr[i], &arr[i+1]);
                isSorted = true;
            }
        }
        right--;

        for(int j=right; j>left; j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap_pointer(&arr[j], &arr[j-1]);
                isSorted = true;
            }
        }
        left++;

        if(!isSorted)
            return;
    }
}

/* Divide and Conquer */
int partition(int arr[],int left,int right)
{
    int key=arr[left];

    while(left<right)
    {
        while(left<right && arr[right]>=key)
        {
            right--;
        }
        arr[left]=arr[right];

        while(left<right && arr[left]<=key)
        {
            left++;
        }
        arr[right]=arr[left];
    }
    arr[left]=key;

    return left;
}

int Partition(int * arr, int start, int end)
{
    int i = start, j = start + 1;
    for (; j <= end; j++)
    {
        if (arr[j] <= arr[start])
        {
            i++;
            swap_quote(arr[i], arr[j]);
        }
    }
    swap_quote(arr[i], arr[start]);

    return i;
}

/* random partition*/
int Randomized_Partition(int * arr, int start, int end)
{
    int i = rand() % (end - start+1) + start;
    int t = arr[i], j = start+1;
    arr[i] = arr[start];
    arr[start] = t;
    i = start;

    for (; j <= end; j++)
    {
        if (arr[j] <= arr[start])
        {
            i++;
            swap_quote(arr[i], arr[j]);
        }
    }
    swap_quote(arr[i], arr[start]);

    return i;
}

/* [......] <  key  <= [......] */
int partition_2(int *arr, int left, int right)
{
    int key = arr[left];
    int j = left;
    for (int i =left+1; i<=right; i++)
    {
        if (arr[i] < key)
        {
            swap_quote(arr[++j],arr[i]);
        }
    }
    swap_quote(arr[left], arr[j]);
    return j;
}

/* quick sort */
void quickSort_2(int arr[],int left,int right)
{
    if(left>=right)
        return;

    //int pivot=partition_2(arr,left,right);
    int pivot=Randomized_Partition(arr,left,right);


    quickSort_2(arr,left,pivot-1);
    quickSort_2(arr,pivot+1,right);
}

/* [......] < [key,key,...,key] < [......] */
void quickSort_3(int *a, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    //Partition
    int key = a[start];
    int i = start;
    int j = start;
    int k = end;
    while (i <= k)
    {
        if (a[i] < key)
        {
            swap_quote(a[i++], a[j++]);
        }
        else if (a[i] > key)
        {
            swap_quote(a[i], a[k--]);
        }
        else
        {
            i++;
        }
    }

    quickSort_3(a, start, j);
    quickSort_3(a, k + 1, end);
}

