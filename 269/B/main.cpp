#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> res[3];
map<int,vector<int> > pos;
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;++i)
   {
        int x;
        cin>>x;
        pos[x].push_back(i);
   }
   vector<int> vals;
   for(auto x:pos)
   {
        if(x.second.size()>=2)
            vals.push_back(x.first);
   }
   bool req = true;
   if(vals.size()<2)
   {

    if(vals.size() == 0)
    {
        cout<<"NO\n";
        return 0;
    }
    if(vals.size() == 1 && pos[vals[0]].size() <= 2)
    {
        cout<<"NO\n";
        return 0;
    }
    else
    {
         req = false;
         for(auto x:pos)
         {
            if(x.first == vals[0])
            {
            res[0].push_back(x.second[0]);
            res[0].push_back(x.second[1]);
            res[0].push_back(x.second[2]);

            res[1].push_back(x.second[1]);
            res[1].push_back(x.second[0]);
            res[1].push_back(x.second[2]);
            res[2].push_back(x.second[2]);
            res[2].push_back(x.second[1]);
            res[2].push_back(x.second[0]);
            for(int i=3;i<x.second.size();++i)
            {
                res[0].push_back(x.second[i]);
                res[1].push_back(x.second[i]);
                res[2].push_back(x.second[i]);
            }
            }
            else
            {
                for(auto y:x.second)
                {
                    res[0].push_back(y);
                    res[1].push_back(y);
                    res[2].push_back(y);
                }

            }


         }
    }





   }

if(req)
{
   for(auto x:pos)
   {
        if(x.first == vals[0])
        {
            res[0].push_back(x.second[0]);
            res[0].push_back(x.second[1]);
            res[1].push_back(x.second[1]);
            res[1].push_back(x.second[0]);
            res[2].push_back(x.second[0]);
            res[2].push_back(x.second[1]);
            for(int i=2;i<x.second.size();++i)
            {
                res[0].push_back(x.second[i]);
                res[1].push_back(x.second[i]);
                res[2].push_back(x.second[i]);
            }


        }
        else if(x.first == vals[1])
        {
            res[0].push_back(x.second[0]);
            res[0].push_back(x.second[1]);
            res[1].push_back(x.second[1]);
            res[1].push_back(x.second[0]);
            res[2].push_back(x.second[1]);
            res[2].push_back(x.second[0]);
                for(int i=2;i<x.second.size();++i)
            {
                res[0].push_back(x.second[i]);
                res[1].push_back(x.second[i]);
                res[2].push_back(x.second[i]);
            }
        }
        else
        {
            for(auto y:x.second)
            {
                res[0].push_back(y);
                res[1].push_back(y);
                res[2].push_back(y);
            }
        }


   }
}
   cout<<"YES\n";
   for(int i=0;i<3;++i)
   {
    for(int j=0;j<res[i].size();++j)
        cout<<res[i][j]<<" ";
    cout<<"\n";
   }






}
