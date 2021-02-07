#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	
    int t;
    cin>>t;
    while(t--)
    {
    	string s;
    	cin>>s;
    	int n=s.length();
    	string best;
    	int best_len=0, c=0;
    	for(int mid=0; mid<n; mid++)
    	{
    		for(int i=0; mid-i>=0 && mid+i<n; i++)
    		{
    			if(s[mid-i]!=s[mid+i])
    				break;
    			else{
    				int len=2*i+1;
                    c++;
    				if(len>best_len)
    				{
    					best_len=len;
    					best=s.substr(mid-i, len);
    				}
    			}
    		}
    	}
    	for(int mid=0; mid<n-1; mid++)
    	{
    		for(int i=1; mid-i+1>=0 && mid+i<n; i++)
    		{
    			if(s[mid-i+1]!=s[mid+i])
    				break;
    			else{
    				int len=2*i;
                    c++;
    				if(best_len<len)
    				{
    					best_len=len;
    					best=s.substr(mid-i+1, len);
    				}
    			}
    		}
    	}
    	cout<<best<<"\n";
        //cout<<c<<"\n";
    }  
  
    
    return 0;
}