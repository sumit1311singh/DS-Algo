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

vector<int> adj[10001];
int vis[10001];
int dis[10001];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		for(int child: adj[curr]){
			if(!vis[child]){
				q.push(child);
				dis[child]=dis[curr]+1;
				vis[child]=1;
			}

		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int n, e;
	cin>>n>>e;
	for(int i=0; i<e; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1);
	cout<<dis[n];
	return 0;
}