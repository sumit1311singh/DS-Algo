#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;

void printallbinary(int k, char str[], int n)
{
	if(n==k){
		str[n]='\0';
		cout<<str<<" ";
		return;
	}
	if(str[n-1]=='1'){
		str[n]='0';
		printallbinary(k, str, n+1);
	}
	else if(str[n-1]=='0'){
		str[n]='0';
		printallbinary(k, str, n+1);

		str[n]='1';
		printallbinary(k, str, n+1);
	}
}

void allbinary(int k)
{
	if(k<=0)
		return;

	char str[k];
	str[0]='0';
	printallbinary(k, str, 1);

	str[0]='1';
	printallbinary(k, str, 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int k;
	cin>>k;
	allbinary(k);
	return 0;
}
