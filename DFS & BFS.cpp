#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
//typedef long long ll;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(vector<vector<int>> adj, int s)
{
	std::stack<int> st;
	st.push(s);
	visited[s]=true;
	while(!st.empty()){
		int node = st.top();
		st.pop();
		cout<<node<<" ";
		for(int i=0; i<adj[node].size(); i++)
		{
			if(!visited[adj[node][i]]){
				st.push(adj[node][i]);
				visited[adj[node][i]]=true;
			}
		}
	}
}
/*
                             1
                     2               3

                 4       5        6        7

               8  9   10 11   12  13    14  15
*/

/*
1 -> 2 3 4 6
2 -> 1 4 5
3 -> 1 6 4
4 -> 2 1 3 5
5 -> 2 4 6
6 -> 3 5 1

stack


output
1 6 5 4 3 2
*/

void bfs(vector<vector<int>> adj, int s){
	queue<int> list;
	list.push(s);
	visited[s]=1;
	while(!list.empty()){
		int node=list.front();
		list.pop();
		cout<<node<<" ";
		for(int i=0; i<adj[node].size(); i++){
			if(!visited[adj[node][i]]){
				list.push(adj[node][i]);
				visited[adj[node][i]]=1;
			}
		}
	}
}
/*
1 -> 2 3 4 6
2 -> 1 4 5
3 -> 1 6 4
4 -> 2 1 3 5
5 -> 2 4 6
6 -> 3 5 1

queue


output
1 2 3 4 6 5

*/

void initialize()
{
	for(int i=0; i<visited.size(); i++)
		visited[i]=false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int n, e;
	cin>>n>>e;
	adj.resize(n+1);
	visited.resize(n+1);
	for(int i=0; i<e; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	initialize();
	bfs(adj, 1);
	cout<<"\n";
	initialize();
	dfs(adj, 1);
	return 0;
}