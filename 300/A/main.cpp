#include <iostream>

using namespace std;
int table[110][110];
int A[110];
int main()
{
    int t; cin>>t;
    for(int kase=1;kase<=t;++kase)
    {
        cout<<"Case "<<kase<<":\n";
        int n,q; cin>>n>>q;
        for(int i=1;i<=n;++i)
            cin>>A[i];
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;++j)
            {
                int mult = 1;
                for(int k=i;k<=j;++k)
                {
                    mult*=A[k];
                    if(mult>106)
                        break;
                }
                table[i][j] = mult;


            }


        while(q--)
        {
            int a,b; cin>>a>>b;
            int minv=10000,l=0,r=-1;
            for(int i=a;i<=b;++i)
                for(int j=i;j<=b;++j)
                {
                    if(table[i][j]<=minv)
                    {
                        cout<<i<<","<<j<<":"<<table[i][j]<<"\n";
                        minv = table[i][j];
                        if((j-i)>(r-l))
                        {
                            l = i;
                            r = j;
                        }
                    }

                }
              for(int i=a;i<=b;++i)
                for(int j=i;j<=b;++j)
                {
                    if(table[i][j]<=minv)
                    {
                        cout<<i<<","<<j<<":"<<table[i][j]<<"\n";
                        minv = table[i][j];
                        if((j-i)>(r-l))
                        {
                            l = i;
                            r = j;
                        }
                    }

                }


            cout<<minv<<" "<<l<<" "<<r<<"\n";


        }



    }

}
