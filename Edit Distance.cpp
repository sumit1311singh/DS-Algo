#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int edit_distance(int i, int j, string s1, string s2, vector<vector<int>> &dp){
	if(i==s1.size())
		return s2.size()-j;
	if(j==s2.size())
		return s1.size()-i;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(s1[i]==s2[j])
		return dp[i][j]=edit_distance(i+1, j+1, s1, s2, dp);
	else{
		int insert=1+edit_distance(i, j+1, s1, s2, dp);
		int remove=1+edit_distance(i+1, j, s1, s2, dp);
		int replace=1+edit_distance(i+1, j+1, s1, s2, dp);
		return dp[i][j]=min(insert,min(remove, replace));
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
		cout<<edit_distance(0, 0, s1, s2, dp);
	}
	return 0;
}
