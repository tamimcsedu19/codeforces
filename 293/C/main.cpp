#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

map<int,ii> idToPos;
map<ii,int> posToId;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1,t=1;i<=n;t++)
    {
        for(int j=i;j<=n && j<i+k;++j)
        {
            int ai; cin>>ai;
            idToPos[ai] = {t,j-i+1};
            posToId[{t,j-i+1}] = ai;
        }

        i=i+k;
    }
//    for(auto x:idToPos)
//    {
//        cout<<x.first<<" ("<<x.second.first<<","<<x.second.second<<")\n";
//    }
    long long int gesCnt = 0;
    while(m--)
    {
        int id; cin>>id;
        auto pos = idToPos[id];
        gesCnt+=pos.first;
        if(pos.first == 1 && pos.second == 1)
            continue;
        ii prev;
        if(pos.second == 1)
        {
            prev.first = pos.first-1;
            prev.second = k;
        }
        else
        {
            prev.first = pos.first;
            prev.second = pos.second-1;
        }
        int nId = posToId[prev];
        idToPos[nId] = pos;
        idToPos[id] = prev;
        posToId[pos] = nId;
        posToId[prev] = id;



    }
    cout<<gesCnt;

}
