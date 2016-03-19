/*************************************************************************
	> File Name: sort.c
    > Include: insertion-sort, merge_sort, bubble_sort, bubble_sort2, heap_sort
    >          quick_sort, counting_sort
	> Author: wenjian
	> Mail: 
	> Created Time: Thu 17 Mar 2016 11:06:36 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "sort.h"


int main(){
    int n, i, j;
    int* a = NULL;
    while(1){
        printf("please input the size of array: ");
        scanf("%d", &n);
        if(n < 0) break;
        a = (int*)malloc(sizeof(int)*n);
        printf("input data:\n");
        for( i=0; i<n; ++i){
            scanf("%d", &a[i]);
        }
//        insertion_sort(a, n);
//        merge_sort(a, 0, n - 1);
//        bubble_sort(a, n);
//        bubble_sort2(a, n);
//        heap_sort(a, n);
//        quick_sort(a, 0, n - 1);
//        quick_sorts(a, n);
        counting_sort(a, n, 9);
        show(a, n);

        free(a);
        a = NULL;
        printf("\n\n");
    }
    return 0;
}
