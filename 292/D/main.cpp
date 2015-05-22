#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char G[2002][2002];
queue<pair<int,int> > q;
char degree[2002][2002];
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
char tileu[4]= {'<','>','^','v'};
char tilev[4]= {'>','<','v','^'};
int main()
{

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; ++i)
        scanf("%s",G[i]+1);

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(G[i][j] == '*')
                continue;
            int deg = 0;
            for(int k=0; k<4; ++k)
            {
                int vx = i+dx[k];
                int vy = j+dy[k];
                if(vx<1 || vy<1 || vx>n || vy >m || G[vx][vy] == '*')
                    continue;
                else
                    ++deg;
            }
            degree[i][j] = deg;
            if(deg == 1)
                q.push({i,j});


        }
    while(!q.empty())
    {
        pair<int,int> u = q.front();
        int i = u.first,j=u.second;
        q.pop();
        if(G[i][j]!='.')
            continue;
        for(int k=0; k<4; ++k)
        {
            int vx = i+dx[k];
            int vy = j+dy[k];
            if(vx<1 || vy<1 || vx>n || vy >m || G[vx][vy] != '.')
                continue;
            else
            {
                G[i][j] = tileu[k];
                G[vx][vy] = tilev[k];
                for(int p=0; p<4; ++p)
                {
                    int vxne = vx+dx[p];
                    int vyne = vy+dy[p];
                    if(vxne<1 || vyne<1 || vxne>n || vyne>m || G[vxne][vyne] != '.')
                        continue;
                    else
                    {
                        --degree[vxne][vyne];
                        if(degree[vxne][vyne] == 1)
                            q.push({vxne,vyne});
                    }
                }



            }
        }
    }

    bool uniq = true;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(G[i][j] =='.')
                uniq = false;
    if(uniq)
    {
        for(int i=1; i<=n; ++i)
            printf("%s\n",G[i]+1);


    }
    else
        printf("Not unique\n");
}
