#include <iostream>
#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int st[4*maxn];
int lazy[4*maxn];
int n;
void build(int u,int l,int r)
{
    int lc=u<<1,rc=lc|1,mid=(l+r)>>1;
    if(l == r)
    {
        st[u] = 1;
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    st[u] = st[lc]+st[rc];
    return;
}
int query(int u,int l,int r,int i,int j)
{
    int lc=u<<1,rc=lc|1,mid=(l+r)>>1;
    if(l>=i && r<=j)
    {
        return st[u];

    }
    if(r<i || l>j) return 0;
    int x=query(lc,l,mid,i,j);
    int y=query(rc,mid+1,r,i,j);
    return x+y;
}


void update(int u,int l,int r,int i,int j,int x)
{

    int lc=u<<1,rc=lc|1,mid1=(l+r)>>1;
    if(l>=i && r<=j)
    {

        st[u]+=x;
        return;
    }
    if(r<i || l>j) return;
    update(lc,l,mid1,i,j,x);
    update(rc,mid1+1,r,i,j,x);
    st[u] = st[lc]+st[rc];
    return;



}

int main()
{
    int q;
    cin>>n>>q;
    build(1,1,n);
    int rightend=0,leftend=n;
    int currwidth = n;
    bool rotated = false;
    while(q--)
    {

        int cm;
        cin>>cm;
        if(cm == 1)
        {
            int add;
            cin>>add;
            if(add > (currwidth-add))
            {
                rotated = !rotated;
                add = currwidth-add;

            }
            int i,j;
            if(rotated == 0)
            {
                for(i = rightend+1,j=rightend+add+add;i<=(rightend+add);++i,--j)
                {
                        int x = query(1,1,n,i,i);
                        update(1,1,n,j,j,x);

                }
                rightend = i-1;
            }
            else
            {

                i = leftend;
                j = leftend-add-add+1;
                while(add--)
                {


                    int x = query(1,1,n,i,i);
                    update(1,1,n,j,j,x);
                    ++j;
                    --i;
                }
                leftend = i;

            }
            currwidth = leftend-rightend;



        }
        else
        {
            int i,j;
            cin>>i>>j;
            if(rotated == 0)
                cout<<query(1,1,n,rightend+i+1,rightend+j)<<"\n";
            else
            {
                int b = leftend-i,a=b-(j-i-1);
                cout<<query(1,1,n,a,b)<<"\n";


            }

        }



    }
}
