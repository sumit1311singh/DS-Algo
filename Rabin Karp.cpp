#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

void rabin_karp(char str[], char pat[])
{
	int n=strlen(str);
	int m=strlen(pat);
	int q=101, d=256;
	int i, j, s=0, p=0, h=1;
	for(int i=0; i<m-1; i++)
		h=(h*d)%q;
	for(int i=0; i<m; i++){
		s=(s*d+str[i])%q;
		p=(p*d+pat[i])%q;
	}
	for(int i=0; i<=n-m; i++){
		if(p==s){
			for(j=0; j<m; j++)
				if(str[i+j]!=pat[j])
					break;
			if(j==m)
				cout<<"found at "<<i<<"\n";
		}
		if(i<n-m){
			s=(d*(s-str[i]*h)+str[i+m])%q;
			if(s<0)
				s+=q;
		}
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
		char str[]="GEEKS FOR GEEKS";
		char pat[]="GEEK";
		rabin_karp(str, pat);
	}
	return 0;
}
