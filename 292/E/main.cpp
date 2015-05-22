#include <iostream>
#include <bits/stdc++.h>
#define maxn 1000007
using namespace std;
typedef long long int ll;


ll cum[2][maxn];
pair<pair<ll,ll>,ll> query(int a,int b)
{
    int mid = (a+b)>>1;
    if(b == a)
    {
        return {{max(cum[0][a],cum[0][b]),max(cum[1][b],cum[1][a])},-1};
    }
    if(b-a == 1)
        return {{max(cum[0][a],cum[0][b]),max(cum[1][b],cum[1][a])},cum[0][a]+cum[1][b]};
    auto l = query(a,mid) , r = query(mid+1,b);
    ll lmax = max(l.first.first,r.first.first);
    ll rmax = max(l.first.second,r.first.second);
    ll bothmax = max(max(l.second,r.second),l.first.first+r.first.second);
    return {{lmax,rmax},bothmax};


}

ll h[maxn];
ll dist[maxn];
ll cumdist[maxn];
int main()
{
    ll n,m; scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        ll x; scanf("%lld",&x);
        dist[i] = dist[i+n] = x;
    }

    for(int i=1;i<=n;++i)
    {
        ll x; scanf("%lld",&x);
        h[i] = h[i+n] = x;
    }
    ll newn = n<<1;
    cumdist[2] = dist[1];
    cum[0][1] = cum[1][1] = 2*h[1];
    cum[0][2] = 2*h[2] - dist[1];
    cum[1][2] = 2*h[2] + dist[1];
    for(int i=3;i<=newn;++i)
    {
        cumdist[i] = cumdist[i-1] + dist[i-1];
        cum[0][i] = 2*h[i] - cumdist[i];
        cum[1][i] = cumdist[i] + 2*h[i];
    }
    while(m--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        if(a>b)
            printf("%lld\n",query(b+1,a-1).second);
        else
            printf("%lld\n",query(b+1,a-1+n).second);


    }



}
