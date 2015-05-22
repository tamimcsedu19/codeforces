#include <iostream>

using namespace std;

int main()
{
  string s;
  cin>>s;
  int l;
  for(l=0;s[l]!='|';++l);
  int r = s.size()-l-1;
  string ws;
  cin>>ws;
  string res;
  if(l<r)
  {
   if(r-l>ws.size())
   {
    cout<<"Impossible"<<endl;
    return 0;
   }
    res = ws.substr(0,r-l).append(s);
    string n = ws.substr(r-l,ws.size());
    if(n.size()%2)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    else
    {
        res = n.substr(0,n.size()/2)+res;
        cout<<res.append(n.substr(n.size()/2));
    }

  }
  else if(r<l)
  {
   if(l-r>ws.size())
   {
    cout<<"Impossible"<<endl;
    return 0;
   }
    res = s.append(ws.substr(0,l-r));
    string n = ws.substr(l-r,ws.size());
    if(n.size()%2)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    else
    {
        res = n.substr(0,n.size()/2)+res;
        cout<<res.append(n.substr(n.size()/2));
    }

  }
  else
  {
    string n = ws;
    if(n.size()%2)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    else
    {
        res = n.substr(0,n.size()/2)+res;
        cout<<res.append(n.substr(n.size()/2));
    }

  }





}
