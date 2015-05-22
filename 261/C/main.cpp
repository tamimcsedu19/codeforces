#include <iostream>

using namespace std;
int n,k,d;
int solns;
int res[1005][1005];
int now[1005];
void bt(int idx)
{
   if(idx == (d+1))
   {
        for(int i=1;i<=d;++i)
            res[solns][i] = now[i];
        solns++;
        return;
   }
   for(int i=1;i<=k;++i)
   {
        now[idx] = i-1;
        bt(idx+1);
        if(solns == n)
            return;

   }
}
int main()
{
    solns = 0;
    int kpowd = 1,cnt = 0;
    cin>>n>>k>>d;
    while(kpowd<1200 && cnt<d)
    {
        kpowd*=k;
        ++cnt;
    }

    if(kpowd<n)
    {
        cout<<-1<<endl;
        return 0;
    }

    bt(1);
    for(int i=1;i<=d;++i)
    {
        for(int j=0;j<n;++j)
                cout<<res[j][i]+1<<" ";
        cout<<"\n";


    }
}
