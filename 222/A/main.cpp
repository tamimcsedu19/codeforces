#include <iostream>
#include <string.h>
using namespace std;
#define unvisited -1

char G[510][510];
bool visited[510][510];
int dfs_counter,n,m,k;
int cnt;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void dfs(int x,int y)
{
    visited[x][y] = true;
    ++dfs_counter;
    if(dfs_counter >= cnt)
        return;
    for(int i=0;i<4;++i)
    {
        int vx = x+dx[i],vy=y+dy[i];
        if(vx >= n || vy >=m || vx<0 || vy < 0 || G[vx][vy] == '#' ||visited[vx][vy])
            continue;
        dfs(vx,vy);
        if(dfs_counter >= cnt)
            return;

    }
}
int main()
{
    cin>>n>>m>>k;
    memset(visited,0,sizeof visited);
    int x=0,y=0;
    cnt = 0;
    dfs_counter = 0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            cin>>G[i][j];
            if(G[i][j] == '.')
            {
               ++cnt;
                x = i;
                y = j;
            }
    }
    cnt-=k;
    dfs(x,y);
     for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(G[i][j] == '.' && !visited[i][j])
                cout<<'X';
            else
                cout<<G[i][j];


        }
        cout<<endl;
       }

}
