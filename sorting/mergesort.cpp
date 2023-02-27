#include <iostream>
#include <algorithm>

void Merge(int data[], int first, int mid, int last){
    int size = last-first+1;
    int * result = new int[size]; 
    int i = first;
    int j = mid+1;

    for(int k = 0; k<size;k++){
        if(i>mid)
            result[k]= data[j++];

        else if(j>last)
            result[k]= data[i++];

        else if(data[i]<=data[j])
            result[k]= data[i++];
        
        else
            result[k]= data[j++];
    }
    for(int n = 0; n<size; n++)
    data[first++]=result[n]; 
    
    delete [] result;
}

void MergeSort(int data[], int first, int last){
    if (first>=last)
    return;

    int mid = first + (last-first)/2;

    MergeSort(data,first, mid);
    MergeSort(data, mid+1, last);
    Merge(data, first, mid, last);
}
