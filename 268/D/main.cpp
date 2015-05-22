#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int a,b;
vector<int> A;
vector<int> st;
vector<ii> sorted;
int bin_search(int l,int r,int val)
{
    if(r<l)
        return -1;
    int mid = (l+r)/2;
    if(sorted[mid].first == val)
        return mid;
    else if(sorted[mid].first > val)
        return bin_search(l,mid-1,val);
    else
        return bin_search(mid+1,r,val);


}

int main()
{


    int n;
    cin>>n>>a>>b;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        A.push_back(x);
        sorted.push_back({x,i});
        st.push_back(-1);
    }

    sort(sorted.begin(),sorted.end());
    bool impos = false;
    //cout<<sorted[bin_search(0,n-1,a-346073)].second;

    for(int i=0;i<n;++i)
    {
        if(st[i]!=(-1))
            continue;
        int x = A[i];
        int sA = (a-x);
        int sB = (b-x);
        int canA = bin_search(0,n-1,sA);
        int canB = bin_search(0,n-1,sB);
        if((canA==-1) && (canB==-1))
        {
            impos = true;
            break;

        }
        else if(canA!=-1)
        {

            st[i]=0;
            st[sorted[canA].second] = 0;
            int c[2]={a,b};
            int fl = 1;
            int x = sorted[canA].first;
            int three;
            while((three=bin_search(0,n-1,c[fl]-x))!=-1)
            {
                st[sorted[three].second] = 0;
                x = c[fl]-x;
                fl = 1-fl;
            }
        }
        else if(canB!=(-1))
        {
            st[i] = 1;
            st[sorted[canB].second] = 1;
            int c[2]={a,b};
            int fl = 0;
            int x = sorted[canA].first;
            int three;
            while((three=bin_search(0,n-1,c[fl]-x))!=-1)
            {
                st[sorted[three].second] = 1;
                x = c[fl]-x;
                fl = 1-fl;
            }



        }
    }
    if(impos)
        cout<<"NO";
    else
    {
        cout<<"YES\n";
        for(int i=0;i<n;++i)
            cout<<st[i]<<" ";
    }



}
