#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int lrs(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
	if(i>=s1.size() || j>=s2.size())
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(s1[i]==s2[j] && i!=j){
		dp[i][j]=lrs(i+1, j+1, s1, s2, dp);
		return 1+dp[i][j];
	}
	else{
		int left=lrs(i+1, j, s1, s2, dp);
		int right=lrs(i, j+1, s1, s2, dp);
		return dp[i][j]=max(left,right);
	}
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
		string s;
		cin>>s;
		int n=s.size();
		//int m=s2.size();
		vector<vector<int>> dp(n, vector<int>(n,-1));
		cout<<lrs(0, 0, s, s, dp);
	}
	return 0;
}
