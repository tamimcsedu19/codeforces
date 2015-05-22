#include <iostream>

using namespace std;

int main()
{
    int n,m,tm,cnt = 0;
    cin>>n>>m;
    tm = m;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        tm-=x;
        if(tm<0)
        {
            ++cnt;
            tm = m-x;

        }


    }
    cout<<cnt+1<<endl;
}
