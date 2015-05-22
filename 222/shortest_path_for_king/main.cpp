#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={1,0,-1,1,0,-1,1,-1};
int cost[10][10];
int parent[70];
bool visited[70];
int main()
{
    memset(parent,-1,sizeof parent);
    memset(visited,0,sizeof visited);
    char a,b;
    cin>>a>>b;
    int s1 = a-'a',s2 = b-'0'-1;
    cin>>a>>b;
    int t1 = a-'a',t2 = b-'0'-1;
    queue<int> q;
    q.push(s2*8 + s1);
    visited[s2*8+s1] = true;
    while(!q.empty())
    {
        int u = q.front(),x=u%8,y=u/8;

        q.pop();
        if(x == t1 && y == t2)
            break;
        for(int i=0;i<8;++i)
        {
            int vx = x+dx[i];
            int vy=y+dy[i];
            int v = vy*8+vx;
            if(vx<0 ||vy<0 || vx>=8 ||vy >=8)
                continue;
            if(!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    int t = t2*8+t1;
    vector<int> path;
    while(parent[t]!=(-1))
    {
        path.push_back(t);
        t = parent[t];


    }
    cout<<path.size()<<endl;
    int u = s2*8+s1;
    for(int i=path.size()-1;i>=0;--i)
    {
        int v = path[i];
        if(v == u+8)
            cout<<"U"<<endl;
        else if(v == u+9)
            cout<<"RU"<<endl;
        else if(v == u+7)
            cout<<"LU"<<endl;
        else if(v == u-7)
            cout<<"RD"<<endl;
        else if(v == u-8)
            cout<<"D"<<endl;
        else if(v == u-9)
            cout<<"LD"<<endl;
        else if( v==u+1)
            cout<<"R"<<endl;
        else if( v == u-1)
            cout<<"L"<<endl;
        u=v;

    }




}
