#include <iostream>
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long int ll;

ll A[maxn],res[maxn],n,m,w;
bool check(ll lowh)
{

    ll days = 0;
    ll i;
    for(i=1;i<=w;i++)
    {
      res[i] = res[i-1] + max(lowh-A[i]-res[i-1],0ll);
      if(res[i]>m)
        return false;
    }

    for(i=w+1;i<=n;++i){
        res[i] = res[i-1]+ max(0ll,lowh-A[i]-(res[i-1]-res[i-w]));
        if(res[i]>m)
            return false;
    }
    return true;
}


int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n>>m>>w;
    for(ll i=1;i<=n;++i)cin>>A[i];
    ll lo = 0,hi=2000000005,mid,res;
    while(lo<hi)
    {
        mid = (lo+hi)/2;
        if(check(mid))
        {
            lo = mid+1;
            res = mid;
        }
        else
            hi = mid;


    }
    cout<<res<<endl;


}
