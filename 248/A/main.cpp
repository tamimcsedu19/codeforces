#include <iostream>

using namespace std;

int main()
{
   int n;
   cin>>n;
   int hcnt=0,hdcnt=0;
   for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(x == 100)
            ++hcnt;
        else
            ++hdcnt;
    }
    int mod1 = hdcnt%2;
    if(hdcnt == 1)
        hcnt-=2;
    if(hcnt < 0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(hcnt%2)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}
