#include <iostream>
#include <string.h>
using namespace std;

int xa[102],ya[102],n;
int dpt[102][603][603];
int bt(int depth,int xsum,int ysum)
{

    if(depth == n)
    {
        if( xsum%2 == 0 && ysum %2 == 0 )
            return 0;
        else return -2;
    }
    if(dpt[depth][xsum][ysum]!=(-1))
        return dpt[depth][xsum][ysum];

    int x = bt(depth+1,xsum+xa[depth],ysum+ya[depth]);
    int y = bt(depth+1,xsum+ya[depth],ysum+xa[depth]);
        if(x<0 && y<0)
            return dpt[depth][xsum][ysum] = -2;
        else if(x<0)
            return dpt[depth][xsum][ysum]=1+y;
        else if(y<0)
            return dpt[depth][xsum][ysum]=x;
        else
            return dpt[depth][xsum][ysum]=min(x,y+1);
}

int main()
{
    cin>>n;
    memset(dpt,-1,sizeof dpt);
    for(int i=0;i<n;++i)
        cin>>xa[i]>>ya[i];
    int res = bt(0,0,0);
        if(res == (-2))
            cout<<-1<<endl;

}
