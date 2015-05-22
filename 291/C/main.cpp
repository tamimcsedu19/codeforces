#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<char,int> G[10000005];

int fin = 0;
void push(string &s,int i,int u)
{
    if(i == s.size())
        return;
    char c = s[i];
    if(G[u].find(s[i]) == G[u].end())
    {
        G[u][s[i]] = ++fin;
        push(s,i+1,fin);
        return;
    }
    else
        push(s,i+1,G[u][s[i]]);

}


bool srch(string &s,int i,int u,int cnt,char prevChar)
{

    if(cnt == 2)
        return false;
    if(i == s.size() )
    {
        if(prevChar == '$')
            return cnt == 1;
        else
            return false;

    }

        bool res = 0;
        for(auto x:G[u])
        {
            if(x.first == s[i])
                res = (res | srch(s,i+1,x.second,cnt,x.first));
            else
                 res = (res | srch(s,i+1,x.second,cnt+1,x.first));

        }
        return res;






}

int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;++i)
   {
        string s;
        cin>>s;
        s = s+"$";
        push(s,0,0);

   }
   while(m--)
   {
        string s;
        cin>>s;
        s = s+"$";
        if(srch(s,0,0,0,'k'))
            cout<<"YES\n";
        else
            cout<<"NO\n";

   }
   return 0;

}
