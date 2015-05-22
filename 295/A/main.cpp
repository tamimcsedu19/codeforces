#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool has[26];
int main()
{
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<s.size();++i)
    {
        int c = tolower(s[i]);
        has[c-'a'] = true;

    }
    for(int i=0;i<26;++i)
    {
        if(!has[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
