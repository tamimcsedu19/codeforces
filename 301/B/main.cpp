#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k,p,x,y;
  cin>>n>>k>>p>>x>>y;
  vector<int> v,pre;

  for(int i=0;i<k;++i)
  {
    int a; cin>>a;
    v.push_back(a);
    x-=a;
  }
  pre = v;
  while(k<n)
  {
    sort(v.begin(),v.end());
    if(k == 0 || (v[((k+1)/2)-1]<y))
    {
        v.push_back(y);
        x-=y;
        ++k;
    }
    else
        break;
  }
  if(x<0)
  {
    cout<<-1<<"\n";
    return 0;
  }
  for(;k<n;++k)
  {
    sort(v.begin(),v.end());
    if(v[((k+1)/2)-1]<y)
    {
        v.push_back(y);
        x-=y;
    }
    else
    {
        v.push_back(1);
        x-=1;
    }



  }




  if(x<0)
  {
    cout<<-1; return 0;
  }
  while(pre.size()>0)
  {
    int i;
    for(i=0;i<v.size();++i)
        if(v[i] == pre[pre.size()-1])
            break;
    v.erase(v.begin()+i);
    pre.pop_back();

  }
  for(int i=0;i<v.size();++i)
    cout<<v[i]<<" ";






}
