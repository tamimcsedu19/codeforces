#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<char> path;
int dest;
int h;
int passes(int u,int lvl,char dir)
{


    if(u == dest)
        return 0;
    if(lvl == h)
        return 1;
    if(dir == path[lvl])
    {
        if(dir == 'L')
            return 1+passes(u<<1ll,lvl+1,'R');
        else
            return 1+passes((u<<1ll)+1,lvl+1,'L');


    }
    else
    {
        if(dir == 'L')
            return (1ll<<(h-lvl))+passes((u<<1ll)+1,lvl+1,'L');
        else
            return (1ll<<(h-lvl))+passes((u<<1ll),lvl+1,'R');
    }


}

 int main()
{

    int n;

    cin>>h>>n;
    dest = n;
    while(n>1)
    {
        if(n%2)
            path.push_back('R');
        else
            path.push_back('L');
        n>>=1;


    }


    reverse(path.begin(),path.end());
    cout<<passes(1,0,'L');




}
