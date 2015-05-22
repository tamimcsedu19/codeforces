#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int nextm[2005];
string s,p;
int calcNext(int si,int pi)
{
    if(pi == p.size())
        return si;
    if(si == s.size())
        return -1;
    if(s[si]==p[pi])
        return calcNext(si+1,pi+1);
    else
        return calcNext(si+1,pi);
}
int dpt[2005][2005];
bool vis[2005][2005];
int dp(int i,int char_to_rem)
{
    if(i==s.size())
    {
        if(char_to_rem == 0)
            return 0;
        else
            return -99999999;
    }

    if(vis[i][char_to_rem])
        return dpt[i][char_to_rem];
    vis[i][char_to_rem] = true;

    int x = dp(i+1,char_to_rem),y=-99999999,z=-99999999;
    if(char_to_rem > 0)
        y = dp(i+1,char_to_rem-1);
    if( (nextm[i]!= -1)&&  (nextm[i]-i-p.size()) <= char_to_rem)
        z = dp(nextm[i],char_to_rem -nextm[i]+i+p.size())+1;
    return dpt[i][char_to_rem] = max(max(x,y),z);




}

int main()
{
    cin>>s>>p;
    for(int i=0;i<s.size();++i)
        nextm[i] = calcNext(i,0);
    for(int i=0;i<s.size();++i)
        cout<<dp(0,i)<<" ";

    cout<<0;


}

