#include <iostream>
#include <limits.h>
#include <set>
using namespace std;
int n,m,i,j,a,b;
int min_move(int x,int y,int cnt,set<int> visited)
{

    if(x>n || y >m || x<1 || y <1)
        return INT_MAX;
    if((x == 1 && y == 1)||(x == 1 && y == m)||(x == n && y == 1) ||(x == n && y == m))
        return cnt;
    int u = n*x + y;
    if(visited.find(u)!=visited.end())
        return INT_MAX;
    visited.insert(u);
    int p = min_move(x-a,y-b,cnt+1,visited);
    int q = min_move(x+a,y-b,cnt+1,visited);
    int r=min_move(x-a,y+b,cnt+1,visited);
    int t=min_move(x+a,y+b,cnt+1,visited);
    return min(min(p,q),min(r,t));
}
int main()
{
    set<int> visited;
    cin>>n>>m>>i>>j>>a>>b;
    int res = min_move(i,j,0,visited);
    if(res == INT_MAX)
        cout<<"Poor Inna and pony!"<<endl;
    else
        cout<<res<<endl;

}
