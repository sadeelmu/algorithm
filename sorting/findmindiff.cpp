#include <iostream>
#include <algorithm>
using namespace std;

void MinDiff(double data[], int first, int mid, int last);
double FindMinDiff(double data[], int first, int last);

//define a value diff to compare 

double diff = 1000000000;

double FindMinDiff(double data[], int first, int last) {
    //check
    if (first >= last)
        return 0;

    int mid = first + (last - first) / 2;

    FindMinDiff(data, first, mid); //divide and conquer 
    FindMinDiff(data, mid + 1, last);

    MinDiff(data, first, mid, last);   
    
    return diff; 
}


void MinDiff(double data[], int first, int mid, int last) {

    int size = last - first + 1;
    double* result = new double[size]; //dynamic array
    int i = first;
    int j = mid + 1;

    for (int k = 0; k < size;k++) {

        if (i > mid)
            result[k] = data[j++];

        else if (j > last)
            result[k] = data[i++];

        else if (data[i] <= data[j])
            result[k] = data[i++];

        else
            result[k] = data[j++];

    }

    for (int n = 0; n < size; n++)
        data[first++] = result[n];

    double min = abs(data[1] - data[0]);

    for (int i = 2; i < size; i++) {
        double minlcl = abs(data[i] - data[i - 1]);

        if (minlcl < min)
            min = minlcl;
    }

    if (min <= diff) //check if final min is less than the original diff
        diff = min;

    delete[] result;

}
