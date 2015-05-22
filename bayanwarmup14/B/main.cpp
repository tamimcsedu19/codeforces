#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int G[405][405];
int n,m;
int translate(int x,int y)
{
    return x*m+y;
}

int main()
{
    cin>>n>>m;
    string hor,ver;
    cin>>hor;
    cin>>ver;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            int u = translate(i,j);
            if(hor[i] == '<')
            {
                if(j!=0)
                    G[translate(i,j)][translate(i,j-1)] = 1;
            }
            else if(hor[i] == '>')
            {
                if(j!=(m-1))
                    G[translate(i,j)][translate(i,j+1)] = 1;

            }
            if(ver[j] == '^')
            {
                if(i!=0)
                    G[translate(i,j)][translate(i-1,j)] = 1;

            }
            else if(ver[j] == 'v')
            {
                if(i!=(n-1))
                   G[translate(i,j)][translate(i+1,j)] = 1;

            }

        }
        for(int k=0;k<n*m;++k)
            for(int i=0;i<n*m;++i)
                for(int j=0;j<n*m;++j)
                    G[i][j] |= (G[i][k] & G[k][j]);
        for(int i=0;i<n*m;++i)
            for(int j=0;j<n*m;++j)
                if(!G[i][j])
                {
                    cout<<"NO";
                    return 0;
                }
        cout<<"YES";
}
