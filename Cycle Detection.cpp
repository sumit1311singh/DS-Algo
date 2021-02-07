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
int f;

void dfs(int s, int visited[])
{
	if(visited[s]==-1){
		f=1;
		return;
	}
	visited[s]=-1;
	cout<<s<<" ";
	for(int i=0; i<adj[s].size(); ++i)
	{
		if(visited[adj[s][i]]!=1){
			dfs(adj[s][i], visited);
		}
	}
	visited[s]=1;
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
	int visited[n+1]={0};
	for(int i=0; i<e; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		//adj[b].push_back(a);
	}
	for(int i=0; i<n; i++)
	{
		if(!visited[i])
			dfs(i, visited);
	}
	/*if(f)
		cout<<"\nloop";
	else
		cout<<"\nno loop";*/
	return 0;
}