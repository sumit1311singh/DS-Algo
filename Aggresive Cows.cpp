#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

bool isvalidconfig(int arr[], int n, int k, int mid)
{
	int prev=0;
	for(int i=1; i<n ;i++){
		if(arr[i]-arr[prev]>=mid){
			k--;
			if(k==1)
				return true;
			prev=i;
		}
	}
	return false;
}

void binsearch(int arr[], int n, int k)
{
	int l=0, h=arr[n-1], mid, ans=-1;
	while(l<=h){
		int mid=l+(h-l)/2;
		if(isvalidconfig(arr, n, k, mid)){
			ans=mid;
			l=mid+1;
		}
		else
			h=mid-1;
	}
	cout<<ans<<"\n";
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
	    int n, c;
	    cin>>n>>c;
	    int arr[n];
	    for(ll i=0; i<n; i++)
	        cin>>arr[i];
	    sort(arr, arr+n);
	    binsearch(arr, n, c);
	}
	return 0;
}