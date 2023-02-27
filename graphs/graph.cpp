#include <list>
#include <queue>
#include <iostream>
using namespace std;

#define WHITE 1
#define GRAY  2
#define BLACK 3

class Graph { 
public:
	Graph(int V);
	~Graph();
	void add_edge(int u, int w);
	void BFT(Graph G, int v);
	bool has_edge(int u, int w);
	void print();
	int V;    // No. of vertices 
	list<int> *adj;  
};

Graph::Graph(int V)	
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 

Graph::~Graph() { delete [] adj; }  


//This function is changed for an undirected graph
//This function now adds an edge from vertex u to vertex w, and also adds an edge from vertex w to vertex u. 
void Graph::add_edge(int u, int w) 
{ 
	adj[w].push_back(u);
    adj[u].push_back(w); 
}


bool Graph::has_edge(int u, int w)
{
	for (int v : adj[u])
		if (v == w) 
			return true;
	return false;
}

void Graph::print()
{
	for (int v = 0 ; v < V ; v++) {
		cout << "[" << v << "]: ";
		for (int w : adj[v])
			cout << w << ", ";
		cout << endl;
	}
}
