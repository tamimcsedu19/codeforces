#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int i;
    int psum = 0;
    for(i=1;i<=n;++i)
    {
        int x = i*i+i;
        x/=2;
        int sum = psum+x;
        if(sum>n)
            break;
        psum = sum;


    }

    cout<<i-1<<endl;

}
