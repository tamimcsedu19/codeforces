#include <iostream>
#include <bits/stdc++.h>
#define maxn 300005
using namespace std;

struct edge{
    int u,v,w;
    edge(){}
    edge(int _f,int _t,int _w):u(_f),v(_t),w(_w){}
    bool operator<(const edge &e) const
    {
        return w<e.w;
    }
};
int max_ending_here[maxn];
vector<edge> E;
int dp[maxn];
int main()
{
    memset(dp,0,sizeof dp);
    E.clear();
    int n,m,sz=0;
    scanf("%d %d",&n,&m);
    int tm = m;
    while(m--)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        edge e(x,y,w);
        E.push_back(e);

    }
    sz = E.size();
    sort(E.begin(),E.end());
   for(int i=0;i<sz;)
   {
    int p = i;
    vector<pair<int,int> > v;
    while(p<sz && E[i].w == E[p].w)
    {
        v.push_back({E[p].v,dp[E[p].u]});
        ++p;

    }
    for(auto x:v)
    {
        dp[x.first] = max(dp[x.first],x.second+1);
        ++i;
    }

   }
    int maxv = 0;
    for(int i=0;i<=n;++i)
        maxv = max(dp[i],maxv);
    cout<<maxv;


}
