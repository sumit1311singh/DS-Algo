#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;

void minchocola(int x_arr[], int y_arr[], int x, int y)
{
	sort(x_arr, x_arr+(x), greater<int>());
	sort(y_arr, y_arr+(y), greater<int>());
	int i=0, j=0, horz=1, vert=1;
	int res=0;
	while(i<x && j<y){
		if(x_arr[i] > y_arr[j]){
			res+=x_arr[i]*vert;
			horz++;
			i++;
		}
		else{
			res+=y_arr[j]*horz;
			vert++;
			j++;
		}
	}
	int total=0;
	while (i < x) 
       	total += x_arr[i++]; 
    res += total * vert; 

   	total=0;
   	while (j < y) 
       	total += y_arr[j++]; 
   	res += total * horz;

   	cout<<res<<"\n";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin>>x>>y;
		int x_arr[x-1], y_arr[y-1];
		for(int i=0; i<x-1; i++)
			cin>>x_arr[i];
		for(int i=0; i<y-1; i++)
			cin>>y_arr[i];
		minchocola(x_arr, y_arr, x-1, y-1);
	}
	return 0;
}
