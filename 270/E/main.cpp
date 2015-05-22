#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> moves;
int G[35][55],n,m;
void relax(int px,int py,int x,int y){ swap(G[x][y],G[px][py]); moves.push_back({x,y}); return; }

ii move(int x,int y,int sx,int sy,int dx,int dy)
{
    int add = (x<=sx)?1:-1;

    while(x!=sx)
        relax(x,y,x+=add,y);
    // check if both y value is same
    bool req=true;

    if(y == sy )
    {
        if(add == -1)
            sx++;
        else
            relax(x,y,x-=1,y);
        if(y==1)
        {
            relax(x,y,x+=1,y+=1);
            relax(x,y,x,y-=1);
            sy++;
        }
        else
            relax(x,y,x+=1,y-=1);
    }
    else
    {
        add = y<sy?1:-1;
        while(y!=sy)
            relax(x,y,x,y+=add);
        if(add == -1)
            sy--;
        else
            relax(x,y,x,y-=1);
    }

    if(x == dx)
    {
        relax(x,y,x-=1,y+=1);
        relax(x,y,x+=1,y);
        relax(x,y,x-=1,y-=1);
        sx--;
    }

    while(x<(dx-1))
    {
        relax(x,y,x+=1,y+=1);
        relax(x,y,x-=1,y);
        relax(x,y,x+=1,y-=1);
        sx++;
    }

    if(y<dy)
    {
        while(y<(dy-1))
        {
            relax(x,y,x-=1,y+=1);
            relax(x,y,x+=1,y+=1);
            relax(x,y,x,y-=1);
            sy++;

        }
    }
    else
    {
        while(y>dy && y > 1)
        {
            relax(x,y,x,y+=1);
            relax(x,y,x-=1,y-=1);
            relax(x,y,x+=1,y-=1);
            sy--;
        }
    }

    if(y == 1 && dy == 1)
    {
        relax(x,y,x+=1,y);
        relax(x,y,x-=1,y+=1);
        sx++;
        sy--;
    }
    else
    {
        relax(x,y,x+=1,y+=1);
        relax(x,y,x-=1,y);
        sx++;
    }
    //assert((sx==dx)&&(sy==dy));
    moves.push_back({-1,-1});
    return {x,y};
}

int target[35][35];
bool vis[35][35];

ii searchf(int val,int dx,int dy)
{
    bool sec = false;
    for(int i=1;i<=dx;++i)
        for(int j=1;j<=(i==dx ? dy:m);++j)
            if(!vis[i][j] && G[i][j] == val)
                return {i,j};


    return {-1,-1};
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>G[i][j];


    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>target[i][j];

    ii x=searchf(target[1][1],n,m);
    vis[x.first][x.second] = true;
    moves.push_back({x.first,x.second});
    for(int i=n;i>2;--i)
        for(int j=m;j>=1;--j)
        {
            ii sx=searchf(target[i][j],i,j);
            x=move(x.first,x.second,sx.first,sx.second,i,j);
        }
    cout<<"\n";
    for(auto x:moves)
    {
        if(x.first == -1)
        {
            cout<<"\n";
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                    cout<<G[i][j]<<" ";
                cout<<"\n";
            }
            cout<<"\n";
        }
        cout<<x.first<<" "<<x.second<<endl;

    }
}
