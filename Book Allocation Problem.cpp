#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//typedef long long ll;

bool isvalidconfig(int arr[], int n, int k, int mid)
{
	int stu=1, sum=0;
	for(int i=0; i<n ;i++){
		if(sum+arr[i]<=mid)
			sum+=arr[i];
		else{
			sum=arr[i];
			stu++;
			if(stu>k)
				return false;
		}
	}
	return true;
}

void binsearch(int arr[], int n, int k)
{
	int l=0, h=0, mid, ans;
	for(int i=0; i<n; i++)
	{
		h+=arr[i];
		l=max(l,arr[i]);
	}
	while(l<=h){
		int mid=l+(h-l)/2;
		if(isvalidconfig(arr, n, k, mid)){
			ans=mid;
			h=mid-1;
		}
		else
			l=mid+1;
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
	    int n, k;
	    cin>>k>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    sort(arr,arr+n);
	    binsearch(arr, n, k);
	}
	return 0;
}