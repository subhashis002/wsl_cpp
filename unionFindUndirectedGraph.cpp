#include<bits/stdc++.h>

using namespace std;

//A structure to represent an edge in graph
class Edge{
	public:
		int src,dest;
};

//a structure to represent a graph
class Graph{
	public:
		int V,E;
		Edge *edge;
};

//create a graph with V vertices and E edges
Graph *createGraph(int V,int E){
	Graph *graph = new Graph();
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[graph->E * sizeof(Edge)];
	return graph;
}

//A utility function to find the subset of an element i
int find(int parent[], int i){
	if(parent[i]==-1)
		return i;
	return find(parent,parent[i]);
}

//A utility funtion to do the union of two set
void Union(int parent[],int x,int y){
	int xset = find(parent,x);
	int yset = find(parent,y);

	if(xset != yset){
		parent[xset] = yset;
	}
}


//The main function to check whether a graph is having a cycle or not
int isCycle(Graph *graph){

	//Allocating memory for creating V subsets
	int *parent = new int[graph->V * sizeof(int)];

	//Initialize all subsets as single element sets
	memset(parent,-1,sizeof(int)*graph->V);

	//iterate through all edges of graph, find subset of both vertices of every edge, if both subset are same, then there is a cycle in graph
	for(int i = 0; i<graph->E; i++){
		int x = find(parent,graph->edge[i].src);
		int y = find(parent,graph->edge[i].dest);

		if(x==y)
			return 1;
		Union(parent,x,y);
	}
	return 0;
}

int main(){
	int V=3,E=3;
	Graph *graph = createGraph(V,E);

	//add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	//add edge 1-2
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	//add edge 0-2
	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;
	
	if(isCycle(graph)){
		cout<<"graph contains cycle";
	}else{
		cout<<"graph doesn't contains cycle";
	}
	return 0;
}
