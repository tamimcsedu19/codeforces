#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <queue>
#define white 1
#define gray 2
#define black 3
using namespace std;




vector<int> G[1005];
int x[1005],y[1005],val[1005];
bool vis[1005];
int dfs(int u)
{
    vis[u] = true;
    int cost = val[u];
    for(int i=0;i<G[u].size();++i)
    {
        int v = G[u][i];
        if(!vis[v])
            cost+=dfs(v);
    }
    return cost;

}


int main()
{
    int n;
    while(cin>>n && n)
    {


    for(int i=1;i<=n;++i)
    {

        cin>>x[i]>>y[i]>>val[i];

        G[i].clear();
        vis[i] = 0;
    }
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
        {
            if(i!=j){
            int dist = ceil(sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])));
            if(dist<=30)
            {
                G[i].push_back(j);
                G[j].push_back(i);

            }
          }
        }
    int maxv = -1,idx = 0;
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            int tot = dfs(i);
            if(tot>maxv)
            {
                maxv = tot;
                idx = i;
            }
        }
    cout<<idx<<" "<<maxv<<endl;

    }

}
