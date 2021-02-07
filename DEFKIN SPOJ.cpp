#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	ll t;
	cin>>t;
	while(t--){
		ll w, h, n, i, temp_x, temp_y;
		cin>>w>>h>>n;
		ll x[n+1], y[n+1];
		for(ll i=0; i<n; i++)
			cin>>x[i]>>y[i];
		sort(x,x+(n));
		sort(y,y+(n));
		x[n]=w+1;
		y[n]=h+1;
		ll max_x, max_y;
		max_x=x[0];
		max_y=y[0];
		for(ll i=1; i<=n; i++){
			temp_x=x[i]-x[i-1];
			temp_y=y[i]-y[i-1];
			if(max_x<temp_x)
				max_x=temp_x;
			if(max_y<temp_y)
				max_y=temp_y;
		}
		//cout<<max_y<<" "<<max_x<<"\n";
		cout<<(max_x-1)*(max_y-1)<<"\n";
	}
	return 0;
}