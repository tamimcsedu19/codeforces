#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dpt[100005][4];
ll x[100005];
ll h[100005];
int n;
ll dp(int idx,int prev_cut)
{
    if(idx == n+1)
        return 0;
    if(dpt[idx][prev_cut]!=(-1))
        return dpt[idx][prev_cut];
    ll res = 0;
    if(prev_cut == (2))
    {
        ll cur = x[idx-1]+h[idx-1];
        if((x[idx]-h[idx])>cur)
            res = max(res,dp(idx+1,0)+1);
        if((x[idx+1])>(x[idx]+h[idx]))
            res = max(res,dp(idx+1,2)+1);
        res = max(res,dp(idx+1,1));

    }
    else
    {
        if((x[idx]-h[idx])>x[idx-1])
            res = max(res,dp(idx+1,0)+1);
        res = max(res,dp(idx+1,1));
        if(x[idx]+h[idx]<x[idx+1])
            res = max(res,dp(idx+1,2)+1);

    }
    return dpt[idx][prev_cut] = res;




}



int main()
{

    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>x[i]>>h[i];
    memset(dpt,-1,sizeof dpt);
    x[0] = -(1ll<<55);
    x[n+1] = (1ll<<54);
    cout<<dp(1,0);
}
