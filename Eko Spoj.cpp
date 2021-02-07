#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;

bool isvalidconfig(ll arr[], ll n, ll k, ll mid)
{
	ll sum=0;
	for(ll i=0; i<n ;i++){
		if(mid<arr[i]){
			sum+=(arr[i]-mid);
		}
	}
	if(sum>=k)
		return true;
	return false;
}

void binsearch(ll arr[], ll n, ll k)
{
	ll l=0, h=arr[n-1], mid, ans;
	while(l<=h){
		ll mid=l+(h-l)/2;
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
	ll q;
	cin>>q;
	while(q--){
	    ll n, t;
	    cin>>n>>t;
	    ll arr[n];
	    for(ll i=0; i<n; i++)
	        cin>>arr[i];
	    sort(arr,arr+n);
	    binsearch(arr, n, t);
	}
	return 0;
}