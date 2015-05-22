#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> G[100005];
int init[100005],goal[100005];
vector<int> ans;
int dfs(int u,int par,int oddCnt,int evenCnt,int lvl)
{
    if(lvl % 2)
    {
        if(oddCnt%2)
            init[u] = 1-init[u];
        if(init[u]!=goal[u])
        {
            ans.push_back(u);
            ++oddCnt;

        }
    }
    else
    {
        if(evenCnt%2)
            init[u] = 1-init[u];
        if(init[u]!=goal[u])
        {
            ans.push_back(u);
            ++evenCnt;

        }

    }
    for(int i=0;i<G[u].size();++i)
    {
        int v = G[u][i];
        if(v!=par)
            dfs(v,u,oddCnt,evenCnt,lvl+1);

    }


}
int main()
{
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;++i)
        cin>>init[i];
    for(int j=1;j<=n;++j)
        cin>>goal[j];
    dfs(1,-1,0,0,1);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<endl;
}
