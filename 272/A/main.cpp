#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long int ll;
int dp[10005];
int n,m;


int main()
{
    cin>>n>>m;
    int minv = INT_MAX;
    for(int y=0;2*y<=n;++y)
    {
        int x = n-2*y;
        if((x+y)%m == 0)
            minv = min(minv,x+y);

    }

    if(minv == INT_MAX)
        cout<<"-1";
    else
        cout<<minv;

}
