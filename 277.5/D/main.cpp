#include <iostream>
#include <bits/stdc++.h>
#define white -1
#define black 1
#define gray 0
using namespace std;

vector<int> G[3005];

int height[3005];
int vis[3005];
int d[3005],f[3005];
int tot;
int tme;
void dfs(int u,int ht)
{
    vis[u] = gray;
    height[u]=ht;
    d[u] = tme++;
    for(int v:G[u])
    {
        if(vis[v] == white)
            dfs(v,ht+1);
        else if(vis[v]==black)
        {
            if(f[v]<d[u])
                tot+=((height[v]-1)*ht);

        }

    }
    vis[u] = black;
    f[u]=tme++;


}

int main()
{
    tot = 0;
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);

    }
    for(int i=1;i<=n;++i)
    {
        memset(vis,-1,sizeof vis);
        tme = 1;
        dfs(i,0);
    }

    cout<<tot<<endl;

}
