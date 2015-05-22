#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n; cin>>n;
   if(n==4)
   {
        cout<<4<<"\n";
        cout<<"3 1 4 2"<<"\n";
        return 0;
   }
   int cnt = 0;
   vector<int> odds,evens;
   for(int i=1;i<=n;++i)
   {
        if(i%2)
            odds.push_back(i);
        else
            evens.push_back(i);
    }
    vector<int> res;
    for(int i=0;i<odds.size();++i)
    {
        res.push_back(odds[i]);
        ++cnt;
    }
    for(int i=0;i<evens.size();++i)
    {
        if(i==0)
        {
            if(odds.size()>=1 && (abs(odds[odds.size()-1]-evens[i])<=1))
                continue;

        }
        res.push_back(evens[i]);
        ++cnt;

    }
    cout<<cnt<<"\n";
    for(int x:res)
        cout<<x<<" ";


}
