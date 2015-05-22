#include <iostream>

using namespace std;
int A[200005];
int main()
{
    int i,j,n,t,c;
    cin>>n>>t>>c;
    for(int i=0;i<n;++i)
        cin>>A[i];
    int prisonerCnt = 0,waysCnt = 0;
    for(j=0;j<c;++j)
        if(A[j]>t)
            ++prisonerCnt;
    if(prisonerCnt == 0)
        waysCnt++;
    i=0;
    --j;
    while(true)
    {
        ++j;
        ++i;
        if(j>=n)
            break;
        if(A[i-1]>t)
            --prisonerCnt;
        if(A[j]>t)
            ++prisonerCnt;
        if(prisonerCnt == 0)
            ++waysCnt;

    }
    cout<<waysCnt<<endl;
}
