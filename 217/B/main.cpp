#include <iostream>
#include <algorithm>
using namespace std;
vector<int> A[102];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int m; cin>>m;
        for(int j=0;j<m;++j)
        {
            int ai;
            cin>>ai;
            A[i].push_back(ai);

        }
        sort(A[i].begin(),A[i].end());

    }

    for(int i=0;i<n;++i)
    {
        bool flag = true;
        for(int j=0;j<n;++j)
        {
            if(i == j || A[j].size()> A[i].size())
                continue;
            int k=0,mmove=0;
            for(k=0;k<A[i].size();++k)
            {
                if(A[i][k] == A[j][mmove])
                    ++mmove;

            }
            if( mmove == A[j].size()){
                flag = false;
                break;
            }

        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;




    }





}
