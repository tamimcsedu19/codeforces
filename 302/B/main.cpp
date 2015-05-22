#include <iostream>

using namespace std;

char grid[102][102];
int main()
{
    int n,k;
    cin>>n>>k;
    int cnt = 0;
    int x,y;
    for(int i=1;i<=n;++i)
    {
        if(cnt>=k)
        {

            break;
        }
        for(int j=1;j<=n;++j)
        {

            if(i%2)
            {
                if(j%2)
                {
                    grid[i][j] = 'L';
                    ++cnt;
                }
            }
            else
            {
                if(!(j%2))
                {
                    grid[i][j] = 'L';
                    ++cnt;

                }

            }
            if(cnt>=k)
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    if(cnt<k)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    if(x%2)
    {
        for(int i=y;i<=n;++i)
            if(i%2)
                grid[x][i] = 'L';

    }
    else
    {
        for(int i=y;i<=n;++i)
            if(i%2 == 0)
                grid[x][i] = 'L';


    }
    ++x;
    if(y!=1)
        y--;

    if(x<=n)
    {
        for(int j=y;j<=n;++j)
            grid[x][j] = 'L';
    }
    ++x;
    for(int i=x;i<=n;++i)
        for(int j=1;j<=n;++j)
            grid[i][j]='L';
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(grid[i][j] == 'L')
                cout<<grid[i][j];
            else
                cout<<'S';
        }
        cout<<"\n";
    }

}
