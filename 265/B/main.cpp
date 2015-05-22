#include <iostream>

using namespace std;
int A[1005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>A[i];
    int moves = 0;
    for(int i=1;i<=n;)
    {
        if(A[i]==0)
        {
            ++i;
            continue;
        }
        int cnt =0;

        int j;
        for(j=i+1;A[j];++j) ++cnt;
        moves+=(cnt+2);
        i=j;



    }
    if(moves)
        cout<<moves-1<<endl;
    else
        cout<<0<<endl;


}
