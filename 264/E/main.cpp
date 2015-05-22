#include <iostream>
#include <bits/stdc++.h>
#define maxn 2000005
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
vector<ll> G[maxn];
ll smallestPrimeDivisor[maxn];
stack<ii> *latest[maxn];
ll val[maxn];
ll ans[maxn];
void seive()
{

    for(ll i=1;i<maxn;++i) smallestPrimeDivisor[i]=i;
    for(ll i=2;i<maxn;i++)
    {
        if(smallestPrimeDivisor[i] == i)
        {
            latest[i]=new stack<ii>();
            for(ll j=i+i;j<maxn;j+=i)
                if(smallestPrimeDivisor[j]>i)
                    smallestPrimeDivisor[j] = i;
        }
    }
}
vector<ll> factors(ll x)
{
    if(x == 1)
        return vector<ll>(1,-1);
    vector<ll> res;
    while(x!=smallestPrimeDivisor[x])
    {
        ll sp = smallestPrimeDivisor[x];
        res.push_back(sp);
        while(x!=1&&(x%sp) == 0)
            x/=sp;

    }
    if(x!=1)
    res.push_back(x);

    return res;

}
ll dfs(ll u,ll h,ll p)
{
    do
    {
        if(val[u]==1)
        {
            ans[u] = -1;
            break;
        }
        vector<ll> pf = factors(val[u]);
        ii maxh={-1,-1};
        for(ll p:pf)
        {
            if(latest[p]->empty())
                continue;
            ii x = latest[p]->top();
            if(x>=maxh)
                maxh = x;


        }
        ans[u] = maxh.second;
        for(ll p:pf)
            latest[p]->push({h,u});

    }while(0);


    for(ll v:G[u]) if(v!=p)
        dfs(v,h+1,u);

    do
    {
        if(val[u] == 1)
            break;
        vector<ll> pf = factors(val[u]);
        for(ll p:pf)
            latest[p]->pop();
    }while(0);
}





int main()
{
   // freopen("out.txt","w",stdout);
    seive();
//    vector<ll> pf = factors(1826622);
//    for(ll v:pf)
//        cout<<v<<" ";

    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;++i)
        cin>>val[i];
    for(ll i=1;i<n;++i)
    {
        ll x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1,0,-1);
    while(q--)
    {
        ll cm;
        cin>>cm;
        if(cm == 1)
        {
            ll v; cin>>v;
            cout<<ans[v]<<"\n";
        }
        else
        {
            ll v ,w;
            cin>>v>>w;
            val[v] = w;
            dfs(1,0,-1);

        }


    }

}
