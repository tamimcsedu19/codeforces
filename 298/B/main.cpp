#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int v1,v2,tim,d;

int dp[102][1500];
int maxCov(int t,int cv)
{

    if(t>=(tim-1))
    {
        if(v2!=cv)
            return -99999999;
        else
            return 0;
    }
    if(dp[t][cv]!=(-1))
        return dp[t][cv];

    int maxv = -9999999;
    for(int i=-d;i<=d;++i)
    {
        maxv = max(maxv,maxCov(t+1,cv+i)+(cv+i));

    }
    return dp[t][cv] = maxv;





}


int main()
{
    cin>>v1>>v2>>tim>>d;
    memset(dp,-1,sizeof dp);
    cout<<maxCov(0,v1)+v1;
}
