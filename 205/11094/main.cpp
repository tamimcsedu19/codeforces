#include <iostream>

using namespace std;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1},m,n;
char A[22][22];
int floodfill(int x,int y,char w)
{
    if(y == n) y = 0;
    if(y == -1) y = n-1;
    if(x<0 || x>=m || A[x][y] == w)
        return 0;
    int ans = 1;
    A[x][y] = w;
    for(int i=0;i<8;++i)
        ans+=floodfill(x+dx[i],y+dy[i],w);
    return ans;
}

int main()
{
    while(cin>>m>>n){
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            cin>>A[i][j];
    int x,y;
    cin>>x>>y;
    char l = A[x][y],w = l;
     for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            if(A[i][j]!=l)
                w = A[i][j];
    floodfill(x,y,w);
    int maxc = -100;
     for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            maxc = max(maxc,floodfill(i,j,w));
    cout<<maxc<<endl;
}


}
