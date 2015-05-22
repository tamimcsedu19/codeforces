#include <iostream>
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int minst[4*maxn],maxst[4*maxn];
int A[maxn];
void build(int u,int l,int r)
{
    int lc = u<<1,rc=lc|1,mid = (l+r)>>1;
    if(l==r)
    {
        minst[u] = maxst[u] = A[l];
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    minst[u] = min(minst[lc],minst[rc]);
    maxst[u] = max(maxst[lc],maxst[rc]);
}
int querymax(int u,int l,int r,int i,int j)
{
    int lc = u<<1,rc=lc|1,mid = (l+r)>>1;
    if(l>=i && r<=j)
        return maxst[u];
    if(l>j || r < i)
        return -1;
    return max(querymax(lc,l,mid,i,j),querymax(rc,mid+1,r,i,j));

}
int querymin(int u,int l,int r,int i,int j)
{
    int lc = u<<1,rc=lc|1,mid = (l+r)>>1;
    if(l>=i && r<=j)
        return minst[u];
    if(l>j || r < i)
        return INT_MAX;
    return min(querymin(lc,l,mid,i,j),querymin(rc,mid+1,r,i,j));

}

int s,l,n;
int dp(int i)
{


    if(i == n)
        return 1;



    int x = i+1;
    int y = x+l-1;
    int res1=,res2=INT_MAX;
    for(;y<=n;++y)
    {
        int maxval = querymax(1,1,n,x,y);
        int minval = querymin(1,1,n,x,y);
        if(maxval-minval <= s)
            break;
    }






}



int main()
{

}
