#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> pos[1005];
vector<int> G[1005];
bool vis[1005];
int dist[1005];
vector<int> topological;
void dfs(int u)
{
    vis[u] = true;
    for(int v:G[u])
        if(!vis[v])
            dfs(v);
    topological.push_back(u);
}



int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> init;
    for(int i=1;i<=k;++i)
        for(int j=1;j<=n;++j)
        {
            int x;
            cin>>x;
            pos[x].push_back(j);

        }
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
        {
            bool isGreater=true;
            bool isSmaller=true;
            for(int p=0;p<k;++p)
            {
                if(pos[i][p] < pos[j][p])
                    isGreater = false;
                if(pos[i][p] > pos[j][p])
                    isSmaller = false;

            }
            if(isSmaller)
                G[i].push_back(j);
            if(isGreater)
                G[j].push_back(i);



        }
        for(int i=1;i<=n;++i)
            if(!vis[i])
                dfs(i);
        for(int i=topological.size()-1;i>=0;--i)
        {
            int u = topological[i];
            for(int v:G[u])
                dist[v] = max(dist[v],dist[u]+1);


        }
        int maxv = 0;
        for(int i=1;i<=n;++i)
            maxv = max(maxv,dist[i]);
        cout<<maxv+1<<"\n";





}
