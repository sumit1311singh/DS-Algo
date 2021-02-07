#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
multiset<string> s;
string temp="";

void print_sub_seq(string str, int pos){
	s.insert(temp);
	for(int i=pos; i<str.length(); i++){
		temp.push_back(str[i]);
		print_sub_seq(str, i+1);
		temp.pop_back();
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
		temp="";
		s.clear();
		string str;
		cin>>str;
		print_sub_seq(str, 0);
		for(auto i:s)
			cout<<i<<"\n";
	}
	return 0;
}
