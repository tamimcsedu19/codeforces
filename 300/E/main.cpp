#include <iostream>
#include <bits/stdc++.h>
#define mn 200005
using namespace std;
vector<int> G[200005];
int hasLeafs[mn];
int maxHave[mn];
int minHave[mn];
int maxstrategy[mn];
int minstrategy[mn];
void dfs(int u,int lvl)
{
    if(G[u].size() == 0)
    {
        hasLeafs[u] = 1;
        minstrategy[u] = 1;
        return;
    }
    for(int v:G[u])
    {
        dfs(v,lvl+1);
        hasLeafs[u]+=hasLeafs[v];
    }
    int maxv = -100000000,minv = 100000000;
    minstrategy[u] = 100000000;
    for(int v:G[u])
    {
        int cur = hasLeafs[u]-hasLeafs[v];
        minstrategy[u] = min(minstrategy[u],cur+minstrategy[v]);
        minv = min(minv,minstrategy[v]);
    }

    if(lvl%2)
    {
        minstrategy[u] = minv;


    }


}
void dfs2(int u,int lvl)
{
    if(G[u].size() == 0)
    {
        maxstrategy[u] = 1;
        return;
    }
    for(int v:G[u])
    {
        dfs2(v,lvl+1);

    }
    int maxv = -100000000,minv = 100000000;
    for(int v:G[u])
    {
        int cur = hasLeafs[u]-hasLeafs[v];
        maxstrategy[u] = max(maxstrategy[u],cur+maxstrategy[v]);
        maxv = max(maxv,maxstrategy[v]);
    }

    if(lvl%2)
    {
        maxstrategy[u] = maxv;

    }


}



int main()
{

    int n; cin>>n;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    dfs(1,0);
    dfs2(1,0);
    cout<<maxstrategy[1]<<" "<<minstrategy[1];

}
