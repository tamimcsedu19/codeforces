#include <iostream>
#include <bits/stdc++.h>
#define unvisited -1
#define explored  0
using namespace std;
vector<int> G[100005];
vector<int> sameVertex[100005];
int dfs_period[100005];
int dfs_low[100005];
int cost[100005];
int dfs_cnt;
bool vis[100005];
vector<int> S;

void dfs(int u)
{

}
int main()
{
    memset(dfs_period,-1,sizeof dfs_period);
    memset(dfs_low,0,sizeof dfs_low);
    memset(vis,0,sizeof vis);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>cost[i];
    int m; cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    dfs_cnt = 1;
    int period = 1;
    for(int i=1;i<=n;++i)
        sort(G[i].begin(),G[i].end());
    for(int i=1;i<=n;++i)
        if(!vis[i])
            dfs(i,period++);
    for(int i=1;i<=n;++i)
    {
        cout<<dfs_low[i]<<" ";
        sameVertex[dfs_low[i]].push_back(cost[i]);
    }
    long long int res = 1 , minCost = 0;
    for(int i=1;i<=n;++i)
    {
        if(sameVertex[i].size() == 0)
            continue;
        sort(sameVertex[i].begin(),sameVertex[i].end());
        long long int minval = sameVertex[i][0],minCnt = 0;
        for(int j=0;j<sameVertex[i].size();++j)
        {
            if(sameVertex[i][j] == minval)
                ++minCnt;
        }
        minCost+=minval;
        res = res*(minCnt%1000000007)%1000000007;

    }
    cout<<minCost<<" "<<res<<endl;
}
