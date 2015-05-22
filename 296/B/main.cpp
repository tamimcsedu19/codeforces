#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s,t;

map<char,vector<int> > mp;
int main()
{
    int x; cin>>x;
    cin>>s>>t;
    int hamming = 0;
    for(int i=0;i<t.size();++i)
    {
        if(s[i]!=t[i])
        {
            mp[s[i]].push_back(i);
            ++hamming;
        }
    }
    int i=-1,j=-1;
    int red = 0;

    for(int k=0;k<s.size();++k)
    {
        if(s[k]!=t[k])
        {
            vector<int> &vec = mp[t[k]];
            for(auto x:vec)
            {
                if(x!=k)
                {
                    if(t[k] == s[x] && s[k] == t[x])
                    {
                        i = x;
                        j = k;
                        red = 2;
                        break;
                    }
                    else
                    {
                        i = x;
                        j = k;
                        red = 1;

                    }

                }

            }
            if(red == 2)
            {
                break;

            }


        }

    }
    cout<<hamming-red<<"\n";
    if(red == 0)
        cout<<-1<<" "<<-1;
    else
        cout<<i+1<<" "<<j+1;



}
