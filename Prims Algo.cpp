#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//typedef long long int ll;
#define V 5

int minKey(int key[], bool mstSet[]) 
{ 
    int min = INT_MAX, min_index; 
 
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
 
    return min_index; 
} 

void primMST(int graph[V][V])
{
	int parent[V]; 
	int key[V];
	bool mstset[V];

	for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstset[i] = false; 

	parent[0]=-1;
	key[0]=0;

	for(int i=0; i<V-1; i++){
		int u=minKey(key, mstset);
		mstset[u]=true;

		for(int v=0; v<V; v++){
			if (graph[u][v] && mstset[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
		}
	}
	cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
    primMST(graph);
	return 0;
}