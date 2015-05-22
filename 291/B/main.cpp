#include <iostream>

using namespace std;
bool checked[1002];
int x[1002];
int y[1002];
int main()
{
    int n,x0,y0;
    cin>>n>>x0>>y0;
    for(int i=0;i<n;++i)
        cin>>x[i]>>y[i];
    int cnt = 0;
    for(int i=0;i<n;++i)
    {
        if(checked[i])
            continue;
        cnt++;
        for(int j=0;j<n;++j)
        {
            if(((x0-x[i])*(y0-y[j])) == ((x0-x[j])*(y0-y[i])))
                checked[j] = true;


        }

    }
    cout<<cnt<<endl;

}
