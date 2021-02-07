#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//typedef long long int ll;

class graph{
public:
	int source, dest, wt;
};

bool compare(graph s1, graph s2)
{
	return s1.wt < s2.wt;
}

int find(int curr, int parent[])
{
	if(parent[curr]==curr)
		return curr;
	return find(parent[curr], parent);
}

void kruskals(graph *mst, int n, int e)
{
	sort(mst,mst+e,compare);
	graph *out = new graph[n-1];

	int *parent= new int[n];
	for(int i=0; i<n; i++)
		parent[i]=i;
	int i=0, count=0;

	while(count!=n-1){
		graph curr = mst[i];
		int source_parent = find(curr.source, parent);
		int dest_parent = find(curr.dest, parent); 

		if(source_parent!=dest_parent){
			out[count]=curr;
			count++;
			parent[source_parent]=dest_parent;
		}
		i++;
	}
	for(int i=0; i<n-1; i++){
		cout<<out[i].source<<" "<<out[i].dest<<" "<<out[i].wt<<"\n";
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
	graph *mst = new graph[e];
	for(int i=0; i<e; i++){
		int s,d,w;
		cin>>s>>d>>w;
		mst[i].source=s;
		mst[i].dest=d;
		mst[i].wt=w;
	}
	kruskals(mst, n, e);
	return 0;
}