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
int in[10001]; 
vector<int> res;
//int dis[10001];

void dfs(int n)
{
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()){
		int curr=q.front();
		res.push_back(curr);
		q.pop();
		for(int child: adj[curr]){
			in[child]--;
			if(!in[child])
				q.push(child);
		}
	}
	for(int child: res)
		cout<<child<<" ";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int n, e;
	cin>>n>>e;
	for(int i=1; i<=e; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		in[b]++;
		//adj[b].push_back(a);
	}
	dfs(n);
	//cout<<dis[n];
	return 0;
}

 /*
                7

            5        4

        2       0         1

            3
                 1