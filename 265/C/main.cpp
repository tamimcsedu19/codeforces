#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string init;
string s;
string fs;
int n;
bool ishere;
bool bt(bool strict,int i,char lastchar,char lastpchar)
{
    if(i==s.size())
    {
        if(ishere)
            return 1;
        ishere = true;
        return false;
    }
    if(strict)
    {
        if(bt(1,i+1,s[i],lastchar))
            return true;
        for(char c = s[i]+1;(c-'a')<n;++c)
        {
            if(c == lastchar || c== lastpchar )
                continue;
            s[i] = c;
            if(bt(0,i+1,c,lastchar))
                return true;


        }
        return false;
    }
    else
    {
        for(char c = 'a';(c-'a')<n;++c)
        {
            if(c == lastchar || c== lastpchar )
                continue;
            s[i] = c;
            if(bt(0,i+1,c,lastchar))
                return true;

        }
        return false;

    }


}



int main()
{
    ishere = false;

    int m;
    cin>>m;
    cin>>n;
    cin>>s;
    bool can = bt(1,0,-1,-1);
    if(can)
        cout<<s;
    else
        cout<<"NO";



}
