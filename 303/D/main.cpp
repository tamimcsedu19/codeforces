#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    vector<int> ts;
    int n; cin>>n;
    for(int i=0;i<n;++i)
    {
        int x; cin>>x;
        ts.push_back(x);
    }
    sort(ts.begin(),ts.end());
    ll cur = 0;
    int cnt = 0;
    for(int x:ts)
    {
        if(cur<=x)
            ++cnt;
        cur+=x;


    }
    cout<<cnt;



}
