#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <queue>
#include <math.h>
#include <climits>
#include "Graph.cpp"

//define colors as integer values
#define white 0
#define gray 1
#define black 2


void HowConnected(int n, int c, string names[], string companies[],int from[], int to[], string name, string target_company){
   //n is the number of vertices in the graph
   //c is the number of edges in the graph

   //names are the vertices in the graph
   //our source is the index of the name given in the names array

   //we use target companies and companies to check if the the current vertix is valid

   //we use from and to for the adjanecy matrix and the adjancey list

   //to find source
   int source = -1;
   for(int i=0;i<n;i++){
      if(names[i]==name){
      source = i;
      break;
      }
   }

   //should test for base case, if source vertix is connected to anything
   //if not connected, it should print "Not Connected"
   //check if adj is zero  if(G.adj[source]==0)  cout<<"discconected";
   //and check source isnt -1
   if(source==-1){
      cout<<"discconected";
      return;
   }

   //intialize graph with n
   Graph G(n);

   //do the adjancey matrix
   for (int i = 0; i < c; i++) {
        G.add_edge(to[i], from[i]); //only do it once cause its a undirected graph
    }

   //BFS Implementation Starts
   //intialize queue of integers to store the vertices we need to proccess
   queue<int> Q; 

   //initalize arrays we need
   //1. array of colors with size the number of vertices in the graph
   int color[G.V];

   //2. array of parent of vertices with size the number of vertices in the graph
   int parent[G.V];

   //3. array of each vertix's distance from the source with size the number of vertices in the graph
   //we will use this to see how far the user is in his connections from that company
   int dist[G.V];

   //initalize the counter from how many users he is connected to from that company
   int company_connections = 0;
   //intialize the distance from how far the user is in his connections from that company
   int distance_from = INT_MAX; //we intialize as unreachable; 

   //fill them with appropiate starting values
   for(int u = 0; u<G.V;u++){
      color[u] = white;
      dist[u] = INT_MAX; //int max is like infinity, something not reachable
      parent[u] = -1;
   }
   //then we proccess source into the queue
   Q.push(source);
   //fix the sources values
   color[source] = black;
   dist[source] = 0;
   //we keep parents as -1 as it has no parent

   //while the queue is not empty 
   while(!Q.empty()){
      //remove a vertex from the graph and add it to the queue
      int newv = Q.front();
      Q.pop();
      //add all neighbors of said vertix
     for (int w : G.adj[newv]){
         //we check if the node has been procceded yet
         if(color[w]==white){
            //change its values
            parent[w] = newv;
            color[w]=gray;
            dist[w]=dist[parent[w]] + 1; //or dist[newv] + 1
            
            //we check if node, which is basically one of the connections at the company, is equal to the target company
            //we also check if it is the shortest 
            if(companies[w]==target_company && dist[w]<=distance_from){
               distance_from = dist[w];
               company_connections++;
            }
            //then add to queue
            Q.push(w);
         }
        color[newv] = black;
      }
   }

   //OUTPUT PART HERE 
   //Your function should print how far is the Target Company 
   //for the given user name, and how many users exist at that level. 
   //if not connected, it should print "Not Connected"

   //to check if its unreachable you just have to check here 
   if(distance_from==INT_MAX)
      cout<<"Not connected";
   else
   cout <<distance_from<<" "<<company_connections<<endl;
}
