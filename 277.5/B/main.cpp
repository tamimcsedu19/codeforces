#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<int,int> capacity[8005],flow[8005],G[8005];

int p[8005],d[8005];
bool bfs()
{
    for(int i=0;i<=8000;++i)
        d[i]=INT_MAX;
    queue<int> q;
    q.push(0);
    p[0] = -1;
    d[0] = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(auto x:G[u])
        {
            if(x.second>0 && d[x.first] > d[u]+1)
            {
                p[x.first] = u;
                d[x.first] = d[u]+1;
                q.push(x.first);
            }


        }

    }
    return d[8000]!= INT_MAX;



}

int ford_fulkerson()
{
    int u,v;
    int max_flow = 0;
    while(bfs())
    {
        int path_flow = INT_MAX;
        for(v=8000;v!=0;v=p[v])
        {
            u = p[v];
            path_flow = min(path_flow,G[u][v]);

        }
        for(v=8000;v!=0;v=p[v])
        {
            u = p[v];
            G[u][v]-=path_flow;
            G[v][u]+=path_flow;

        }
        max_flow+=path_flow;
    }
    return max_flow;


}

int A[102],B[102];
int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>A[i];
    cin>>m;
    for(int j=1;j<=m;++j)
        cin>>B[j];
    for(int i=1;i<=n;++i)
    {
        G[0][i] = 1;
        for(int j=1;j<=m;++j)
            if(abs(A[i]-B[j])<=1)
                G[i][n+j+1] = 1;


    }
    for(int i=1;i<=m;++i)
        G[n+i+1][8000] = 1;
    cout<<ford_fulkerson()<<endl;


}
