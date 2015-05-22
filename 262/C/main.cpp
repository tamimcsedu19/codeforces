#include <iostream>
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
long long int A[maxn];
pair<int,int> st[4*maxn];
int lazy[4*maxn];
void build(int u,int l,int r)
{
    if(l == r)
    {
        st[u].first = l;
        st[u].second = A[l];
        return;
    }
    int lc = u*2,rc=lc+1,mid = (l+r)/2;
    build(lc,l,mid);
    build(rc,mid+1,r);
    if(st[lc].second<=st[rc].second)
    {
        st[u].first = st[lc].first;
        st[u].second = st[lc].second;
    }
    else
    {
        st[u].first = st[rc].first;
        st[u].second = st[rc].second;

    }
}
void update(int u,int l,int r,int i,int j)
{
    if(l>j||r<i) return;
    if(l>=i&&r<=j)
    {
        st[u].second++;
        lazy[u]++;
        return;
    }
    int lc = u*2,rc=lc+1,mid = (l+r)/2;
    update(lc,l,mid,i,j);
    update(rc,mid+1,r,i,j);
    if(st[lc].second <= st[rc].second)
    {
        st[u].first = st[lc].first;
        st[u].second = st[lc].second+lazy[u];

    }
    else
    {
        st[u].first = st[rc].first;
        st[u].second = st[rc].second+lazy[u];

    }
}

int main()
{
    long long int n,m,w;
    cin>>n>>m>>w;
    for(long long int i=1;i<=n;++i)
        cin>>A[i];
    build(1,1,n);
    while(m--)
        update(1,1,n,st[1].first,min(n,st[1].first+w-1));
    cout<<st[1].second;


}
