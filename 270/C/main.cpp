#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<string,string> ss;
ss init[100005];
ss sorted[100005];
int selected[100005];
int main()
{

  int n;
  cin>>n;
  for(int i=1;i<=n;++i)
  {
    cin>>init[i].first>>init[i].second;
    if(init[i].first>init[i].second)
        swap(init[i].first,init[i].second);
  }
  for(int i=1;i<=n;++i)
  {
    int x;
    cin>>x;
    sorted[i] = init[x];

  }
  bool strict=false;
  bool pos = true;
  for(int i=1;i<n;++i)
  {

        if(!strict)
        {
            string cs = sorted[i].first;
            if(cs<sorted[i+1].first)
                continue;
            else if(cs<sorted[i+1].second)
                strict = true;
            else
            {
                pos = false;
                break;
            }


        }
        else
        {
            string cs = sorted[i].second;
            if(cs<sorted[i+1].first)
            {
                strict = false;
                continue;
            }
            else if(cs<sorted[i+1].second)
                continue;
            else
            {
                pos = false;
                break;
            }

        }



  }
  if(pos)
    cout<<"YES";
  else
    cout<<"NO";



}
