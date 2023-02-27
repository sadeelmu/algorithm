#include <iostream>
using namespace std;

void Create2DArray(int** &data, int R, int C) {
	data = new int* [R];
	for (int i = 0; i < R; i++)
		data[i] = new int[C];
}

int CountingApples(int** apples, int N, int M)
{

    // base case: if the start or end cell is blocked, return 0
    if (apples[0][0] < 0 || apples[N - 1][M - 1] < 0)
    return 0;
    
    // create a 2D array to store the results
    int** result = NULL;
    Create2DArray(result, N, M);
    
    int left = 0, up = 0, left_up = 0;

    for(int i = 0; i <N;i++){
        for(int j = 0;j<M;j++){
            result[i][j]=0;
        }
    }

    // set the value of the start cell in the result array
    result[0][0] = apples[0][0];

    //first column handled here [0] to handle if there is a blocked cell in the first column
    for(int r = 1; r<N;r++){
        left = 0;
        up = 0; 
        left_up = 0;

        if(apples[r][0]>0)
            result[r][0]=result[r-1][0] + apples[r][0];
        else
            break;
    }

    // fill the result array using bottom-up approach starting from the second column
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {

            // skip blocked cells
            if (apples[i][j] <= 0) //add equal sign to make sure if the value = 0 it recognizes that it is blocked
            {
                if(i==0) //checks that the first row has a blocked apple
                break;
                else
                {
                result[i][j] = 0;
                continue;
                }
            }

            // values of the left, up, and left-up cells
            left = 0;
            up = 0; 
            left_up = 0;
                
            if((j>0 && apples[i][j-1]<0))
            left=0; //zero them out to ensure that it isnt considered as 0
            else if(j>0 && apples[i][j-1]>0)
            left = result[i][j-1];
                
            if((i>0 && apples[i-1][j]<0)||i==0)
            up=0;
            else if(i>0 && apples[i-1][j]>0)
            up = result[i-1][j];

                
            if((i>0 && j>0 && apples[i-1][j-1]<0)||(i==0 && j==0))
            left_up=0;
            else if(i>0 && j>0 && apples[i-1][j-1]>0)
            left_up = result[i-1][j-1];

            
            result[i][j] = max(left, max(up, left_up)) + apples[i][j];
            if ((left == 0 && up == 0 && left_up == 0) && (i>0 && j>0)){
            result[i][j] = 0;
            }
           
	   }
   } 
 
   return result[N-1][M-1];
}
