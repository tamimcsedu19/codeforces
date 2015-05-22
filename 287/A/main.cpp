#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n; cin>>n;
   int k;
   cin>>k;
   vector<pair<int,int> > A;
   for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        A.push_back({x,i+1});
    }
    sort(A.begin(),A.end());

    vector<int> res;
    int sum = 0;
    for(auto x:A)
    {
        if(x.first+sum<=k)
        {
            sum+=x.first;
            res.push_back(x.second);
        }
        else
            break;

    }

    cout<<res.size()<<"\n";
    for(auto i:res)
        cout<<i<<" ";


}
