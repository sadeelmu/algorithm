#include <iostream>
#include <algorithm>
using namespace std;
#include <math.h>


int MinSubscription(int D, int * Days, int * Prices){
	//base case no experimentation days
	if(D==0) return 0;
	//if D exceeds 365
	if(D==366) return 0;  //should throw error in the case of c++. type T  
	//intalize size for array and then array
	int size = Days[D-1]+1;
	int mincost[size];
	//if it is the day D
	mincost[size-1]=min(Prices[0], min(Prices[1], Prices[2]));
	//pointer in order to traversal
	int days_finished=D-2; 
	for(int i=size-2; i>0;i--){//we start from size-2 as we already initialized size-1
		//intializing the variables
		int sub1 = 0;
		int sub2 = 0;
		int sub3 = 0;
		if((days_finished>=0) && (Days[days_finished]==i)){
			//subscription option 1-day
			sub1 = mincost[i+1] + Prices[0];
			
			//subscription option 7-day
			if (i+7>=size) {
			sub2=Prices[1];
			} else {
			sub2=Prices[1]+mincost[i+7];
			}

			//subscription option 30-day
			if (i+30>=size) {
			sub3=Prices[2];
			} else {
			sub3=Prices[2]+mincost[i+30];
			}
			//store the value of the updated min value
			mincost[i] = min(sub1, min(sub2, sub3));
			days_finished--; //to traverse the array of Days we use the days_finished inside 
		}
		else{
			mincost[i] = mincost[i+1];
		}
	}
    return mincost[1];
}
