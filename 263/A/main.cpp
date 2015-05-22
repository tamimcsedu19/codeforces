#include <iostream>
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef pair<int,int> ii;


char grid[105][105];
int main()
{


    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>grid[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            int cnt = 0;
            if(i>0 && grid[i-1][j]=='o')
                ++cnt;
            if(j>0 && grid[i][j-1] == 'o')
                ++cnt;

            if(i<n && grid[i+1][j]=='o')
                ++cnt;
            if(j<n && grid[i][j+1]=='o')
                ++cnt;
            if(cnt%2)
            {
                cout<<"NO";
                return 0;

            }

        }
   cout<<"YES";
}
