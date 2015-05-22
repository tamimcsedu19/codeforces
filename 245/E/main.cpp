#include <bits/stdc++.h>
using namespace std;

int nxtNode[25],has[25],need[25];
int n;
bool bt(int u,int nodes)
{


    if(u == n+1)
    {
        for(int i=1;i<=n;++i)
            if(has[i]!=need[i])
                return 0;
        return 1;
    }
    while(nxtNode[nodes] == 0) --nodes;
    has[u] = 1;
    need[u] = nodes;
    bool ans = 0;
    for(int v=1;v<u;++v)
    {
        if(has[v]+nodes <= need[v]  && nodes+1 < need[v])
        {
            has[v]+=nodes;
            --nxtNode[nodes];
            ans = bt(u+1,nodes) || ans;
            has[v]-=nodes;
            ++nxtNode[nodes];
            if(nodes == 1)
                break;

        }


    }
    return ans;


}


int main()
{
    memset(nxtNode,0,sizeof nxtNode);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        ++nxtNode[x];

    }
    has[1] = 1;
    need[1] = n;
    if(bt(2,n-1))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;



}
