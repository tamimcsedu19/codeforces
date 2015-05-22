#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lefti[102],righti[102];
vector<pair<int,int> > soln;
int main()
{
    memset(lefti,0,sizeof lefti);
    memset(righti,0,sizeof righti);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        int color;
        cin>>color;
        ++lefti[color];
        ++righti[color];

    }
    for(int k=0;k<m;++k){
        for(int i=1;i<=m;++i)
        {
            if(lefti[i] == 0)
                continue;
            for(int j=1;j<=m;++j)
            {
                if(i == j || righti[j] == 0)
                    continue;
                soln.push_back({i,j});
                --righti[j];
                --lefti[i];
                if(lefti[i] == 0)
                    break;
            }

        }
    }
    cout<<soln.size()<<endl;
    for(int i=1;i<=m;++i)
    {
        if(lefti[i] == 0)
            continue;
        for(int j=1;j<=m;++j)
        {
            if(righti[j] == 0)
                continue;
            while(righti[j]> 0  && lefti[i]>0)
             {
                soln.push_back({i,j});
                --righti[j];
                --lefti[i];
            }
            if(lefti[i] == 0)
                break;
        }

    }


    for(int i=0;i<soln.size();++i)
        cout<<soln[i].first<<" "<<soln[i].second<<endl;


}
