/*************************************************************************
	> File Name: algorithm.c
	> Author: wenjian 
	> Mail: 
	> Created Time: Thu 17 Mar 2016 11:32:40 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "sort.h"

/* output all elems of array */
void show(int *a, int n){
    int i = 0;
    for(i = 0; i < n; ++i){
        printf("a[%d] = %d  ", i, a[i]);
    }
    printf("\n");
}

/* insertion sort */
void insertion_sort(int *a, int n){
    int i, j, key;
    for( i = 1; i < n; ++i){
        j = i - 1;
        key = a[i];
        while(a[j] > key && j >= 0){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}

/* merge sort */
void merge(int *a, int p, int q, int r){
    int i, j, k,n1, n2;
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1+1], R[n2+1];
    for(i = 0; i < n1; ++i){
        L[i] = a[p + i];
    }
    for(j = 0; j < n2; ++j){
        R[j] = a[q + j + 1];
    }
    L[n1] = 9999;
    R[n2] = 9999;
    i = 0;
    j = 0;
    for(k = p; k <= r; ++k){
        if(L[i] <= R[j]){
            a[k] = L[i];
            ++i;
        }
        else{
            a[k] = R[j];
            ++j;
        }
    }
}

void merge_sort(int* a, int p, int r){
    if(p < r){
        int q = (p + r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

/* Bubble sort */
void bubble_sort(int *a, int n){
    int i, j, tmp;
    for(i = 0; i < n-1; ++i){
        for(j = 0; j < n - i - 1; ++j){
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

/* Bubble sort using flag */
void bubble_sort2(int *a, int n){
    int i, j, tmp, pos;
    i = n - 1;
    while(i > 0){
        pos = 0;
        for(j = 0; j < i; ++j){
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                pos = j;
            }
        }
        i = pos;
    }
}

/* exchange array. a[0..n-1] -> a[1..n] */
int* changearray(int *a, int n){
    int i = 0;
    int *b = malloc(sizeof(int)*(n+1));
    while(i < n){
        b[i+1] = a[i];
        ++i;
    }
    return b;
}

void freearray(int *a){
    free(a);
}

/* Heap sort */
int parent(int i){
    return i/2;
}

int left(int i){
    return 2 * i;
}

int right(int i){
    return 2 * i + 1; 
}

void max_heapify(int *a, int i, int heap_size){
    int l = left(i);
    int r = right(i);
    int largest;
    if(l <= heap_size && a[l] > a[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= heap_size && a[r] > a[largest]){
        largest = r; 
    }
    if(largest != i){
        int tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        max_heapify(a, largest, heap_size);
    }

}

void  build_maxheap(int *a, int n){
    int i;
    for(i = n/2; i > 0; --i){
        max_heapify(a, i, n);
    }
}

void heap_sort(int *b, int n){
    int *a = changearray(b, n);
    build_maxheap(a, n);
    int i = n;
    while(i > 1){
        int tmp = a[1];
        a[1] = a[i];
        a[i] = tmp;
        --i;
        max_heapify(a, 1, i);
    }
    for(i = 0; i < n; ++i){
        b[i] = a[i+1];
    }
    freearray(a);
}

/* quick sort */
int partition(int *a, int p, int r){
    int x = a[r];
    int i = p - 1;
    int j, tmp;
    for(j = p; j <= r - 1; ++j){
        if(a[j] < a[r]){
            ++i;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;
    return i+1;
}

// a[0..n]
void quick_sort(int *a, int p, int r){
    if(p < r){
        int q = partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
}

// b[0..n-1] -> a[1..n]
void quick_sorts(int *b, int n){
    int *a = changearray(b , n);
    quick_sort(a, 1, n);
    int i;
    for(i = 0; i < n; ++i){
        b[i] = a[i+1];
    }
    free(a);
}

/* counting sort */
void counting_sort(int *d, int n, int k){
    int *a = changearray(d, n); //a[1..n]
    int *b = (int*)malloc(sizeof(int)*(n+1)); //b[1..n]
    int *c = (int*)malloc(sizeof(int)*(k+1)); //c[0..k]
    int i, j;
    for(i = 0; i<= k; ++i){
        c[i] = 0;
    }
    for(j = 1; j <= n; ++j){
        c[a[j]] += 1; 
    }
    for(i = 1; i <= k; ++i){
        c[i] += c[i-1];
    }
    for(j = n; j >= 1; --j){
        b[c[a[j]]] = a[j];
        c[a[j]] -= 1;
    }

    for(i = 0; i < n; ++i){
        d[i] = b[i+1];
    }

    free(b);
    free(c);
    freearray(a);
}

