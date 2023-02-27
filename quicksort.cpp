
#include <iostream>
#include <algorithm>
#include <math.h>

void InnerQuickSort(int data[], int first, int last, int frames);
int Partition(int data[], int first, int last);
void InsertionSort(int data[], int n);

void QuickSort(int data[], int first, int last) {
    if(first>=last)
    return;
    
    int frames = 1;

    InnerQuickSort(data, first, last,  frames);
    InsertionSort(data, last-first+1);
}

void InnerQuickSort(int data[], int first, int last, int frames){
    if(first>=last)
    return;
    if((last-first+1<=16) || (frames>=20)){
    return;
    }

    int p = Partition(data, first, last);

    InnerQuickSort(data, first, p -1, ++frames);
    InnerQuickSort(data, p+1, last, ++frames);
}

int Partition(int data[], int first, int last) {
    int pivotIndex = rand()%(last-first+1)+first;
    swap(data[pivotIndex], data[first]);
    int pivot = data[first];
    int i = first;
    int j = last+1;
    while(true){
        do {i = i+1;}
        while((i<last) && (data[i]<=pivot));
        do {j = j-1;}
        while((j>first) && (data[j]>pivot));
        if(i>=j)
        break;

        else{
            swap(data[i], data[j]);
        }
    }
    swap(data[first], data[j]);
    return j;
}

void InsertionSort(int data[], int n){
    for(int i = 1;i<n;i++){
        int temp = data[i];
        int j;
        for(j=i-1;j>=0 && temp < data[j];j--)
            data[j+1] = data[j];
        data[j+1]=temp;
    }
}



