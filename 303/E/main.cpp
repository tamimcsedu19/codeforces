#include <iostream>
#include <bits/stdc++.h>
#define maxn 300005

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<long long int,ll> li;
const ll inf=(1ll<<55);
vector<ii> G[maxn];
ll d[maxn];
ll par[maxn];
ll e[maxn];
int n,k;
ll viscnt[maxn];
map<ii,ii> edges;
set<ii> minEdge;
set<int> dijkstra(int s,int k)
{

    priority_queue<ii,vector<ii>,greater<ii> > pq;
    pq.push({0,s});

    par[s] = -1;
    d[s] = 0;
    while(!pq.empty())
    {

        ll u = pq.top().second,scoreu = pq.top().first;
        pq.pop();
        if(viscnt[u]>=1)
            continue;
        ++viscnt[u];
        for(int i=0;i<G[u].size();++i)
        {
            ll scorenow = scoreu+G[u][i].second,v=G[u][i].first;
            if(scorenow<d[v])
            {

                    d[v] = scorenow;
                    par[v] = u;
                    e[v] = G[u][i].second;
                    pq.push({scorenow,v});


            }
            else if(scorenow == d[v])
            {
                if(par[v]!=(-1))
                {
                    if(G[u][i].second < e[v])
                    {
                            par[v] = u;
                            e[v] = G[u][i].second;
                            //pq.push({scorenow,v});
                    }


                }


            }
        }

    }
    set<int> res;
    ll minval = 0;
    for(int i=1;i<=n;++i)
    {
        int u = i,v = par[u];
        while(v!=(-1) || !viscnt[u])
        {
            auto itr = edges.find({min(u,v),max(u,v)});
            auto x = res.insert(itr->second.first);
            if(x.second)
                minval+=itr->second.second;
            viscnt[u] = true;
            u = v;
            v = par[u];

        }

    }



    printf("%lld\n",minval);
    return res;


}
int main()
{
    //freopen("in.txt","r",stdin);
    int m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
    {
            G[i].clear();
            viscnt[i] =0;
            d[i] = inf;
            par[i] = -1;
    }
    int num = 1;
    while(m--)
    {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back({v,w});
            G[v].push_back({u,w});
            edges[{min(u,v),max(u,v)}]={num,w};
            ++num;

    }
    int u; cin>>u;
    auto res = dijkstra(u,-1);
    for(auto x:res)
        printf("%d ",x);






}
