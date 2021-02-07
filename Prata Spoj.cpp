#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//typedef long long int ll;

bool isvalidconfig(int arr[], int num, int pratanum, int mid)
{
	int n = 0;
    for(int i=0;i<num;i++)
    {
        int t = 0;
        int next_time = arr[i];
        while(t + next_time<=mid)
        {
            n += 1;
            t += next_time;
            next_time += arr[i];
            if(n >= pratanum)
                return true;
        }
    }
    return false;
	
}

void prata(int arr[], int num, int pratanum)
{
	int low=0, high, mid, s=arr[num-1], ans=-1;
	high=(pratanum*(pratanum+1)*s)/2;

	while(low<=high){
		mid=low+(high-low)/2;
		if(isvalidconfig(arr, num, pratanum, mid)){
			ans=mid;
			high=mid-1;
		}
		else
			low=mid+1;
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
	    int pratanum, num;
	    cin>>pratanum>>num;
	    int arr[num];
	    for(int i=0; i<num; i++)
	        cin>>arr[i];
	    sort(arr,arr+num);
	    prata(arr, num, pratanum);
	}
	return 0;
}