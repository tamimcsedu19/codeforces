#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int recruited=0,crime=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(x == -1 && recruited == 0)
            ++crime;
        else if(x == -1)
            --recruited;
        else
            recruited+=x;
    }
    cout<<crime<<endl;
}
