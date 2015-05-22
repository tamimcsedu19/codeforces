#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

priority_queue<ii> pq[3];
int categoryHighest[3];
int main()
{
    categoryHighest[0] = 0;
    categoryHighest[1] = 1;
    categoryHighest[2] = 2;

    int n; cin>>n;
    for(int i=1;i<=n;++i)
    {
        int ai; cin>>ai;
        pq[ai%3].push({-ai,i});
    }
    vector<int> res;
    for(int i=1;i<=n;++i)
    {
        int category = (i-1)%3;
        if(pq[category].empty())
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
        ii cur = pq[category].top();
        pq[category].pop();
        int prevP = -cur.first,num = cur.second;
        if(prevP >= i)
        {
            cout<<"Impossible"<<endl;
            return 0;

        }
        if(prevP == categoryHighest[category] || (prevP == categoryHighest[category]+3))
        {
            res.push_back(cur.second);
            if(prevP == categoryHighest[category]+3)
                categoryHighest[category]+=3;
        }
        else
        {
            cout<<"Impossible"<<endl;
            return 0;
        }


    }
    cout<<"Possible\n";
    for(int x:res)
        cout<<x<<" ";




}
