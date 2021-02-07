#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
	return 0;
}

void findpath(int m[MAX][MAX], int n, vector<string> &res, string path, int i, int j)
{
	if(i<0 || i>=n || j<0 || j>=n || m[i][j]!=1)
		return;
	if(i==n-1 && j==n-1){
		res.push_back(path);
		return;
	}
	m[i][j]=-1;
	findpath(m,n,res,path+'D',i+1,j);
	findpath(m,n,res,path+'L',i,j-1);
	findpath(m,n,res,path+'R',i,j+1);
	findpath(m,n,res,path+'U',i-1,j);
	m[i][j]=1;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> res;
    string path="";
    findpath(m,n,res,path,0,0);
    return res;
}