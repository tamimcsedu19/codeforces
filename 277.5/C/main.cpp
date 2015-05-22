#include <iostream>

using namespace std;
int res[105];
int m,s;
int res2[105];


int main()
{
    cin>>m>>s;
    if(m == 1 && s== 0)
    {
        cout<<0<<" "<<0;
        return 0;
    }
    if(s==0)
    {
        cout<<-1<<" "<<-1;
        return 0;
    }
    int ts = s;
    res[1] = -1;
    for(int i=1;i<=9;++i)
    {
        if((ts-i)<=(m-1)*9)
        {
            res[1] = i;
            ts-=i;
            break;

        }

    }
    if(res[1] == -1)
    {
        cout<<-1<<" "<<-1;
        return 0;
    }
    for(int j=2;j<=m;++j)
    {
        for(int i=0;i<=9;++i)
        {
            if((ts-i)<=(m-j)*9)
            {
                res[j] = i;
                ts-=i;
                break;

            }

        }


    }
    for(int i=1;i<=m;++i)
        cout<<res[i];

   cout<<" ";
    for(int i=m;i>=1;--i)
        cout<<res[i];



}
