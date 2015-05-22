#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll addingval[100];
ll lastOcc[100];
ll wt[100];
ll cum[100005];
map<ll,ll> mp[100];
int main()
{

    for(int i=0;i<26;++i)
        cin>>wt[i];
    string s; cin>>s; int sz = s.size();
    s = "$" +s;
    long long int cnt = 0;

    for(int i=1;i<=sz;++i)
    {
        char c = s[i] - 'a';
        cum[i] = cum[i-1] + wt[c];
        cnt += mp[c][cum[i-1]];
        mp[c][cum[i]] ++;


    }
    cout<<cnt;


}
