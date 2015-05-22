#include <iostream>
#include <vector>
using namespace std;
vector<int> G[2005];
int cost[2005][2005];
bool
int bfs(int u)
{



}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cost[i][j] = 0;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(x == -1)
            continue;
        else
            G[x].push_back(i);

    }


}
