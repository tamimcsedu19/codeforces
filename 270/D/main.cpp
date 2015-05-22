#include <iostream>

using namespace std;

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;

ll dist[2004][2004];
vector<ii> graph[2004];
ll dist2[2004][2004];
bool vis[2004];
int n;
int dfsd(int root,int u,int d)
{
    vis[u] = true;
    for(ii x:graph[u])
    {
        int v = x.first,w=x.second;
        if(!vis[v])
        {
            dist2[root][v] = w+d;
            dfsd(root,v,w+d);

        }

    }
}



vector<ii> tgraph[2004];

int main()
{
    ios_base::sync_with_stdio(0);

    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>dist[i][j];
    int u = 1;
    while(true)
    {
        ll maxv = -1,maxid;
        for(int v=1;v<=n;++v)
            if(u!=v && dist[u][v]!=0 && !vis[v])
            {
                if(dist[u][v]>maxv)
                {
                    maxv = dist[u][v];
                    maxid = v;
                }
            }
        vis[maxid] = true;
        if(maxv == -1)
            break;
        int minv = INT_MAX,minid;
        for(int i=1;i<=n;++i)
            if(!vis[i] && dist[maxid][i]<minv)
            {
                minid = i;
                minv = dist[maxid][i];
            }
        if(minv == INT_MAX || dist[maxid][minid]!=dist[minid][maxid])
        {
            cout<<"NO";
            return 0;
        }
        graph[minid].push_back({maxid,dist[maxid][minid]});
        graph[maxid].push_back({minid,dist[maxid][minid]});
        u = minid;




    }




    for(int u=1;u<=n;++u)
    {
        memset(vis,0,sizeof vis);
        dfsd(u,u,0);
    }

    bool connected = true;


//    for(int i=1;i<=n;++i)
//    {
//        for(int j=1;j<=n;++j)
//        {
//            cout<<graph[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(dist2[i][j]!=dist[i][j])
                connected = false;
            else if(i!=j && (dist2[i][j] == 0))
                connected = false;
    if(connected)
        cout<<"YES";
    else
        cout<<"NO";

}
