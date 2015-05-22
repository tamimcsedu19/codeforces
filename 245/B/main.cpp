#include <iostream>

using namespace std;


int A[105];
int main()
{

   int n,k,x;
   cin>>n>>k>>x;
    int realX = x;
   A[0] = -1;
   A[n+1] = -1;
   int pos,maxCnt = 0;
   for(int i=1;i<=n;++i)
    cin>>A[i];
   for(pos = 1;pos<=n;++pos)
   {
    x = realX;
    int cnt = 1,total = 0;
    int i=pos,j=pos+1;
    while(true)
        {
        while(A[i] == x){ --i; ++cnt;}
        while(A[j] == x){ ++j; ++cnt;}
        if(cnt>=3)
        {

            total+=cnt;
            if(A[i] == -1 || A[j] == -1)
                break;
            x = A[i];
            cnt = 0;
        }
        else
            break;


        }
    if(total>maxCnt)
    {
      //  cout<<pos<<" "<<maxCnt<<" "<<total<<endl;
        maxCnt = total;
    }
    }
    cout<<max(maxCnt-1,0)<<endl;

}
