#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;

int partition(int arr[], int start, int end)
{
	int pivot=arr[end], pIndex=start;
	for(int i=start; i<end; i++){
		if(arr[i]<=pivot){
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex], arr[end]);
	return pIndex;
}

void quicksort(int arr[], int start, int end)
{
	if(start>=end) 
		return;
	int pIndex = partition(arr, start, end);
	quicksort(arr, start, pIndex-1);
	quicksort(arr, pIndex+1, end);
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
	int start=0, end=n-1;
	quicksort(arr, start, end);
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	return 0;
}