#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int d[2000005];
int main()
{
    ll n,A; cin>>n>>A;
    ll sum = 0;
    for(int i=1;i<=n;++i)
    {
        cin>>d[i];
        sum+=d[i];
    }
    for(int i=1;i<=n;++i)
    {
        ll total = sum-d[i];
        ll haveTo = A-total;

        ll cnt =0;
        if(haveTo>=1)
            cnt += haveTo -1;
        total = n-1;
        haveTo = A-total;
        if(d[i]>=haveTo)
            cnt+=(d[i]-haveTo);
        cout<<cnt<<" ";


    }


}
