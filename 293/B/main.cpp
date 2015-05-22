#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<char,int> f;
bool taken[200005];
int main()
{
    string s,t; cin>>s>>t;
    int yaycnt = 0, whopcnt = 0;
    for(int i=0;i<t.size();++i)
        f[t[i]]++;
    for(int i=0;i<s.size();++i)
    {
        if(f[s[i]]>0)
        {
            ++yaycnt;
            --f[s[i]];
            taken[i]=true;
        }
    }
     for(int i=0;i<s.size();++i)
     {
        if(!taken[i])
        {
            if(isupper(s[i]) && f[tolower(s[i])]>0)
            {
                ++whopcnt;
                --f[tolower(s[i])];
            }
            if(islower(s[i]) && f[toupper(s[i])]>0)
            {
                ++whopcnt;
                --f[toupper(s[i])];
            }
        }
     }

    cout<<yaycnt<<" "<<whopcnt;

}
