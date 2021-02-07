#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int lcs(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
	if(i>=s1.size() || j>=s2.size())
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(s1[i]==s2[j]){
		//dp[i][j]=lcs(i+1, j+1, s1, s2, dp);
		return 1+dp[i][j];
	}
	else{
		int left=lcs(i+1, j, s1, s2, dp);
		int right=lcs(i, j+1, s1, s2, dp);
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
		string s1, s2;
		cin>>s1>>s2;
		int n=s1.size();
		int m=s2.size();
		vector<vector<int>> dp(n, vector<int>(m,-1));
		cout<<lcs(0, 0, s1, s2, dp);
	}
	return 0;
}
