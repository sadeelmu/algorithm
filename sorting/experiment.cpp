#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100000001;

// Set this to true if you wish the arrays to be printed.
const bool OUTPUT_DATA = false;


void ReadInput(string& sortAlg, string& dataStatus, int& size);

void GenerateSortedData(int data[], int size);
void GenerateReverselySortedData(int data[], int size);
void GenerateRandomData(int data[], int size);
void GenerateNearlySortedData(int data[], int size);
void GenerateSortedRunsData(int data[], int size);

void Sort(int data[], int size, string sortAlg, string dataType);

void InsertionSort(int data[], int size);

void MergeSort(int data[], int first, int last);
void Merge(int data[], int first, int mid, int last);
void MergeSortWithInsertion(int data[], int first, int last);
void QuickSort(int data[], int first, int last);
int Partition(int data[], int first, int last);


void Swap(int& x, int& y);

bool IsSorted(int data[], int size);
void printData(int data[], int size, string title);


int main(void)
{
	int size;
	string sortAlg, dataStatus;
	ReadInput(sortAlg, dataStatus, size);



	int* data = new int[size];

	if (dataStatus=="S"){
		GenerateSortedData(data, size);
		Sort(data, size, sortAlg, "Sorted Data");
	}
	else if  (dataStatus=="R"){
		GenerateReverselySortedData(data, size);
		Sort(data, size, sortAlg, "Reversely Sorted Data");
	}
	else if  (dataStatus=="D"){
		GenerateRandomData(data, size);
		Sort(data, size, sortAlg, "Random Data");
	}

	else if  (dataStatus=="N"){
		GenerateNearlySortedData(data, size);
	    Sort(data, size, sortAlg, "Nearly Sorted Data");
	}
	else {
		GenerateSortedRunsData(data, size);
		Sort(data, size, sortAlg, "Data with sorted runs");
	}
	cout << endl << "================================" << endl;

	


	cout << "\nProgram Completed Successfully." << endl;;

	return 0;
}
/********************************************************************/




// This function asks the user to choose the sorting algorithm and the array size
void ReadInput(string& sortAlg, string& dataStatus, int& size)
{
	cout << "  I:\tInsertion Sort" << endl;
	cout << "  M:\tMerge Sort " << endl;
	cout << "  Q:\tQuick Sort " << endl;

	cout << "Enter first sorting algorithm: ";
	cin >> sortAlg;
	cout << endl;

	cout << "Seletec the status of input data you will be testing with "<<endl;
	cout << "  S:\tSorted" << endl;
	cout << "  R:\tReversely Sorted " << endl;
	cout << "  D:\tRandom  " << endl;
    cout << "  N:\tNearly Sorted  " << endl;
    cout << "  U:\tSorted runs  " << endl;


	cin >> dataStatus;
	string sortAlgName, dataStatusName;


    if (sortAlg == "I")
		sortAlgName = "Insertion Sort";
	else if (sortAlg == "M")
		sortAlgName = "Merge Sort";
	else if (sortAlg == "Q")
		sortAlgName = "Quick Sort";

	else {
		cout << "\nUnrecognized sorting algorithm Code: " << sortAlg << endl;
		exit(1);
	}

    if (dataStatus == "S")
		dataStatusName = "Sorted Data";
	else if (dataStatus == "R")
		dataStatusName = "Reversely Sorted Data";
	else if (dataStatus == "D")
		dataStatusName = "Random Data";
	else if (dataStatus == "N")
		dataStatusName = "Nearly Sorted Data";	
	else if (dataStatus == "U")
		dataStatusName = "Data with Sorted Runs";
	
	else {
		cout << "\nUnrecognized data status option: " << dataStatus << endl;
		exit(1);
	}

	cout << "Enter input size: ";
	cin >> size;

	if (size < 1 || size > MAX_SIZE)
	{
		cout << "\nInvalid input size " << size
			<< ". Size should be between 1 and " << MAX_SIZE << endl;
		exit(1);
	}

	cout << "\nSorting Algorithm: " << sortAlgName << " with " << dataStatusName;
	cout << "\nInput Size = " << size << endl;


}
/******************************************************************************/




void GenerateSortedData(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		data[i] = i * 3 + 5;
}

/*****************************************************************************/




void GenerateReverselySortedData(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		data[i] = (size - i) * 2 + 3;

}
/*****************************************************************************/




void GenerateRandomData(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		data[i] = rand();
}
/*****************************************************************************/




void GenerateNearlySortedData(int data[], int size)
{
	int i;

	GenerateSortedData(data, size);

	for (i = 0; i < size; i++)
		if (i % 10 == 0)
			if (i + 1 < size)
				data[i] = data[i + 1] + 9;
}
/*****************************************************************************/
void GenerateSortedRunsData(int data[], int size) {
	int i, j, k, run_size;

	i = 0;
	while (true) {
		run_size = rand() % 30;
		k = rand() % 100000;
		//create  a sorted run
		for (j = 0; j < run_size && i < size; j++) {
			data[i++] = k + (j * 3 + 5);
		}
		if (i >= size)
			break;
		k = rand() % 100000;
		//create  a unsorted run
		run_size = rand() % 30;
		for (j = 0; j < run_size && i < size; j++) {
			data[i++] = rand();
		}
		if (i >= size)
			break;

	}


}
// This function performs sorting depending on the algorithm chosen by the user.
void Sort(int data[], int size, string sortAlg, string dataType)
{

	cout << endl << dataType << ":";


	if (OUTPUT_DATA)
		printData(data, size, "Data before sorting:");



	// Sorting is about to begin ... start the timer!
	clock_t start = clock();


	if (sortAlg == "I")
		InsertionSort(data, size);
	else if (sortAlg == "M")
		MergeSort(data, 0, size - 1);
	else if (sortAlg == "Q")
		QuickSort(data, 0, size - 1);



	else
	{
		cout << "Invalid sorting algorithm!" << endl;
		exit(1);
	}

	// Sorting has finished ... stop the timer!
	clock_t end = clock();
	double elapsed = (((double)(end - start)) / CLOCKS_PER_SEC) * 1000;



	if (OUTPUT_DATA)
		printData(data, size, "Data after sorting:");


	if (IsSorted(data, size))
		cout << " Correctly sorted " << size << " elements in " << elapsed << "ms";
	else
		cout << "ERROR!: INCORRECT SORTING!" << endl;
	//cout << "\n-------------------------------------------------------------\n";
}
/*****************************************************************************/




bool IsSorted(int data[], int size)
{
	int i;

	for (i = 0; i < (size - 1); i++)
	{
		if (data[i + 1] < data[i])
			return false;
	}
	return true;
}
/*****************************************************************************/







void InsertionSort(int data[], int n)
{
 for(int i = 1;i<n;i++){
        int temp = data[i];
        int j;
        for(j=i-1;j>=0 && temp < data[j];j--)
            data[j+1] = data[j];
        data[j+1]=temp;
    }

}



void MergeSort(int data[], int first, int last) {
    if (first>=last)
    return;

    int mid = first + (last-first)/2;

    MergeSort(data,first, mid);
    MergeSort(data, mid+1, last);
    Merge(data, first, mid, last);
	
}

void Merge(int data[], int first, int mid, int last) {
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


void QuickSort(int data[], int first, int last) {
 	if(first>=last)
    return;

    int p = Partition(data, first, last);
   
     QuickSort(data, first, p -1);
     QuickSort(data, p+1, last); 
    
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




void Swap(int& x, int& y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;

}
/*****************************************************************************/




void printData(int data[], int size, string title) {
	int i;

	cout << endl << title << endl;
	for (i = 0; i < size; i++)
	{
		cout << data[i] << " ";
		if (i % 10 == 9 && size > 10)
			cout << endl;
	}
}
