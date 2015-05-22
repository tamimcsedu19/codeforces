#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> Z,X;
int main()
{
   int p,q,l,r;
   cin>>p>>q>>l>>r;
   for(int i=0;i<p;++i)
   {
    int a,b;
    cin>>a>>b;
    Z.push_back({a,b});
   }
   for(int i=0;i<q;++i)
   {
    int a,b;
    cin>>a>>b;
    X.push_back({a,b});

   }
   int cnt = 0;
   for(int i=l;i<=r;++i)
   {
        bool flag = false;
        for(int j=0;j<q;++j)
        {
            int cxA = X[j].first+i,cxB=X[j].second+i;
            for(int k=0;k<p;++k)
            {
                if(cxB<Z[k].first || cxA > Z[k].second)
                    continue;
                ++cnt;
                flag = true;
                break;

            }
            if(flag)
                break;


        }
    }
    cout<<cnt;









}
