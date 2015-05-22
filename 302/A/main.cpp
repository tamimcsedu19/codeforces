#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f[26];
int main()
{
    int k; cin>>k;
    string s; cin>>s;
    for(int i=0;i<s.size();++i)
    {
        ++f[s[i]-'a'];
    }
    int cnt = 0;
    for(int i=0;i<26;++i)
    {
        if(f[i])
            ++cnt;
    }
    if(cnt>=k)
        cout<<"YES\n";
    else
    {
        cout<<"NO\n";
        return 0;
    }

    set<char> prev;
    int i,j=1;
    for(i=0;i<s.size() && j<k;)
    {
        prev.insert(s[i]);
        cout<<s[i];
        ++i;
        while(i<s.size() && (prev.find(s[i]) !=prev.end()))
        {
            cout<<s[i];
            ++i;
        }
        cout<<"\n";
        ++j;

    }
    for(;i<s.size();++i)
        cout<<s[i];


}
