#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif
void swap_quote(int &x, int &y); //quote
void swap_pointer(int *x, int *y); //pointer
void swap_qp(int *(&x), int *(&y)); //quote & pointer

void printArr(int *arr, int n); //print arr

void bubbleSort(int *arr, int n); //bobbleSort
void cocktailSort(int *arr, int n); //cocktailSort
void quickSort_2(int arr[],int left,int right);  //quickSort
void quickSort_3(int *a, int start, int end); //quickSort_3


#ifdef __cplusplus
}
#endif

#endif
