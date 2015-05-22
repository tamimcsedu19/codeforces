#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<ii> G[100005];
int d[100005];
int n,m,a,k,currSafe;
int dijkstra(int s)
{
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    pq.push({0,s});
    if(d[s] == INT_MAX)
        --currSafe;
    d[s] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second,w = pq.top().first; pq.pop();
        if(d[u]<w)
            continue;
        for(int i=0;i<G[u].size();++i)
        {
            int tw = G[u][i].second,v=G[u][i].first;
            if(w+tw < d[v] && w+tw < k)
            {
                if(d[v] == INT_MAX)
                    --currSafe;
                d[v] = w+tw;
                pq.push({w+tw,v});

            }

        }


    }


}


int main()
{


    while(scanf("%d %d %d %d",&n,&m,&a,&k))
    {
        if(n == 0 && m == 0 && a == 0 && k == 0)
            break;
        for(int i=0;i<=n;++i)
        {
              d[i]=INT_MAX;
              G[i].clear();
        }
        while(m--)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back({v,w});
            G[v].push_back({u,w});

        }
        currSafe = n;
        while(a--)
        {
            int b;
            scanf("%d",&b);
            dijkstra(b);
            printf("%d\n",currSafe);

        }
        printf("\n");






    }


}



