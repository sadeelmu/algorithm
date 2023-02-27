
#include <iostream>
#include <algorithm>
#include "minpq.cpp"
#include "Graph.cpp"
#include <string>
#include <queue>
#include <math.h>
#include <climits>

//V number of vertices
//E1 is the number of edges for the first graph G1
// E2 is the number of edges for the second graph G2
bool CheckMST (int V,int E1,int E2,int from1[],int to1 [],int Weight1[],int from2[],int to2[],int Weight2[]){
    //one should implement the Prim's algorithm

    //check edges = v-1
    if (E2 != V-1) {
        return false;
    }

    int mst_edges=0;

    // a priority queue for graph 1 of vertices ordered by dist[]
    //MinPQ pq1 = MinPQ<int> (V);
    //MinPQ pq2 = MinPQ<int> (V);

    
    // stores the minimum spanning tree for graph 1
    //int parent1[V];
    // stores the shortest distances to the current MST for graph 1
    int dist1[V];
    //variable to find total distance later
    int total_dist1=0;


    // a priority queue for graph 2 of vertices ordered by dist[]
    //Graph G1(V);
    //Graph G2(V);    


    // stores the minimum spanning tree for graph 1
    //int parent2[V];
    // stores the shortest distances to the current MST for graph 1
    int dist2[V];
    //variable to find total distance later
    int total_dist2=0;
    
    //relaxing
    for(int i = 0; i<V;i++){
        //parent1[i]=-1;
        dist1[i]=INT_MAX;
        //parent2[i]=-1;
        dist2[i]=INT_MAX;
    }

    //inserting
    dist1[0]=0;
    dist2[0]=0;

     //for (every vertex w adjacent to v):
    for(int u=0;u<V-1;u++){
        for(int w=0;w<E1;w++){
            if(dist1[from1[w]] +Weight1[w]<dist1[to1[w]])
                    dist1[to1[w]]=dist1[from1[w]]+Weight1[w];
            }
            mst_edges++;
        }

    for(int d1 = 0; d1<V; d1++)
        total_dist1 += dist1[d1];

    for(int u=0;u<V-1;u++){
        for(int w=0;w<E1;w++){
            if(dist2[from2[w]] +Weight2[w]<dist2[to2[w]])
                    dist2[to2[w]]=dist2[from2[w]]+Weight2[w];
            }
        }

    for(int d2 = 0; d2<V; d2++)
        total_dist2 += dist2[d2];

     if (total_dist1 == total_dist2 && mst_edges==E2) 
        return true;
    else 
         return false;
}
