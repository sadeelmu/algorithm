#include <algorithm>
using namespace std;
#include <iostream>

//bottom up
int MaxDriverPay(int n, int*  L, int* H) {
  //base case zero days
  int maxincome[n+1];
  maxincome[0] = max(L[0], H[0]); // base case
  maxincome[1] = max(H[1], L[1]+maxincome[0]); //base case 
  //we start the for loop at i = 2 this way we ensure if we take heavy load it has a day to prepare
  for (int i = 2; i <= n; i++) {

    int lightload;
    //in this case lightload is selected that day
    //we add to lightload the one day before
    lightload= maxincome[i-1] + L[i];

    int heavyload;
    //in this case heavyload is selected that day
    //we add to heavyload the two days before to ensure that we have a days rest
    heavyload = maxincome[i-2] + H[i]; 

    maxincome[i] = max(lightload, heavyload);
  }
  return maxincome[n];
}


