#include <iostream>

using namespace std;
char A[105][105];
int main()
{
    int x,y;
    cin>>x>>y;
    for(int i=0;i<x;++i)
    {
        if(i%2)
            A[i][0] = 'B';
        else
            A[i][0] = 'W';
        for(int j=1;j<y;++j)
            if(A[i][j-1] == 'W')
                A[i][j] = 'B';
            else
                A[i][j] = 'W';

    }
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<y;++j)
        {
            char c;
            cin>>c;
            if(c == '-')
                cout<<'-';
            else
                cout<<A[i][j];

        }
        cout<<endl;
    }


}
