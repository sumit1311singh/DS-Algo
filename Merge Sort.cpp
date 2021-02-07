#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;

void merge(int arr[], int larr[], int l, int rarr[], int r)
{
	int i=0, j=0, k=0;
	while(i<l && j<r){
		if(larr[i]<=rarr[j])
			arr[k++]=larr[i++];
		else
			arr[k++]=rarr[j++];
	}
	while(i<l)
		arr[k++]=larr[i++];
	while(j<r)
		arr[k++]=rarr[j++];
}

void mergesort(int arr[], int n)
{
	if(n<2)
		return;
	int mid=n/2;
	int larr[mid], rarr[n-mid];
	for(int i=0; i<=mid-1; i++)
		larr[i]=arr[i];
	for(int i=mid; i<=n-1; i++)
		rarr[i-mid]=arr[i];
	mergesort(larr, mid);
	mergesort(rarr, n-mid);
	merge(arr, larr, mid, rarr, n-mid);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	mergesort(arr, n);
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	return 0;
}
