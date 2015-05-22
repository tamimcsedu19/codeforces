#include <iostream>
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef pair<int,int> ii;
typedef long long int ull;
ull freq[27];
ull k;
ull dpt[27][maxn];
bool vis[27][maxn];
ull dp(int idx,int taken)
{
   sort(freq,freq+26,greater<int>());
   ull res = 0;
   for(int i=0;i<26;++i)
    {
        if(k>freq[i])
        {
            res+=(freq[i]*freq[i]);
            k-=freq[i];
        }
        else
        {
            res+=(k*k);
            break;
        }

    }
    return res;
}

int main()
{
    memset(freq,0,sizeof freq);
    memset(vis,0,sizeof vis);
    int n;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i)
        freq[s[i]-'A']++;

    cout<<dp(0,0);



}
