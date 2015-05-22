#include <iostream>
#include <bits/stdc++.h>
#define m 1000000007
using namespace std;
typedef long long int ll;
ll dp1[100005];
string chars("ATCG");
string s;
map<char,int> f;
ll dpCal1(int idx)
{
    if(idx == s.size())
        return 0;
    ll maxv = 0;
    if(dp1[idx]!= (-1))
        return dp1[idx];
    for(int i=0;i<chars.size();++i)
    {
        maxv = max(maxv,f[chars[i]] + dpCal1(idx+1));
    }
    return dp1[idx] = maxv;


}
ll dp2[100005];

ll dpC2(int idx)
{
    if(idx == (s.size()-1))
    {
        int cnt = 0;
       for(int i=0;i<chars.size();++i)
            if(f[chars[i]] == dp1[idx])
                ++cnt;
        return cnt;
    }
    if(dp2[idx]!=(-1))
        return dp2[idx];


    ll cnt = 0;
    for(int i=0;i<chars.size();++i)
    {
        if(f[chars[i]] + dp1[idx+1] == dp1[idx])
            cnt = (cnt+dpC2(idx+1)) % m;
    }
    return dp2[idx] = cnt;

}



int main()
{
    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);
    int n; cin>>n;
    cin>>s;
    for(int i=0;i<s.size();++i)
        f[s[i]]++;

    dpCal1(0);
    cout<<dpC2(0);

}
