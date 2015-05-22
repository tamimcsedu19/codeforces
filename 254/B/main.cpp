#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long int> G[55];
bool vis[55];
long long int deg[55];
long long int bfs(long long int u,long long int danger)
{
    queue<long long int> q;
    q.push(u);
    vis[u] = 1;
    while(!q.empty())
    {
        long long int u = q.front();
        q.pop();
        for(long long int i=0;i<G[u].size();++i)
        {
            long long int v = G[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                danger*=2;
                q.push(v);
            }
        }


    }
    return danger;

}
int main()
{

   long long int n,m;
   cin>>n>>m;
   memset(vis,0,sizeof vis);
   memset(deg,0,sizeof deg);
   while(m--)
   {
        long long int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        ++deg[x];
        ++deg[y];

   }
   vector<pair<long long int,long long int> > order;
   long long int danger = 1;
   for(long long int i=1;i<=n;++i)
    order.push_back({deg[i],i});
   sort(order.begin(),order.end());
   for(long long int i=0;i<n;++i)
   {
    if(!vis[order[i].second])
    {
        danger = bfs(order[i].second,danger);

    }
   }
   cout<<danger<<endl;

}
