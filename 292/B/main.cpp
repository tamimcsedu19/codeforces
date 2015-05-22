#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool boys[102];
bool girls[102];
int main()
{
    int n,m; cin>>n>>m;
    int b; cin>>b;
    for(int i=0;i<b;++i)
    {
        int x; cin>>x;
        boys[x] = 1;
    }
    int g; cin>>g;
    for(int i=0;i<g;++i)
    {
        int x; cin>>x;
        girls[x] = 1;
    }
    for(int i=0;i<10000000;++i)
    {
        int boy = i%n;
        int girl = i%m;
        if(boys[boy] || girls[girl])
        {
            boys[boy] = girls[girl] = 1;
        }


    }
    bool unHappy = false;
    for(int i=0;i<n;++i)
        if(!boys[i])
            unHappy = true;
    for(int i=0;i<m;++i)
        if(!girls[i])
            unHappy = true;
    if(unHappy)
        cout<<"No";
    else
        cout<<"Yes";

}
