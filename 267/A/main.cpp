#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int cnt = 0;
    for(int i=0;i<n;++i)
    {
        int p,q;
        cin>>p>>q;
        if(p+2 <=q)
            ++cnt;
    }
    cout<<cnt;
}
