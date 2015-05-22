#include <iostream>
#include <bits/stdc++.h>
#define inf 1000000
using namespace std;
int curr_state[50],n;
int lim,nlim,result;
int dx[4][4] = {
{ -3, -1, +4, -4 },
{ +1, +3, +4, -4 },
{ +1, -1, +4, -4 },
{ +1, -1, +4, -4 }
};
int manhattan_distance(int p1,int p2);
int dh(int curr_point,int prev_point,int val) //delta
{
return manhattan_distance(curr_point,val)-manhattan_distance(prev_point,val);
}
int h1()
{
int h = 0;
for(int i=1;i<=n;++i)
h+=manhattan_distance(i,curr_state[i]);
return h;
}
int parents[50];
bool dfs(int depth,int cost ,int parent,int i)
{
parents[i] = parent;
if(depth+cost > lim)
{
nlim = min(nlim,depth+cost);
return false;
}
if(!cost){
result = depth;
return true;
}
int *d = dx[i % 4];
for (int j = 0; j < 4; j++)
{
int k = i + d[j];
if (k < 1 || k > n || k == parent) continue;
int d = - manhattan_distance( curr_state[ k ],k) + manhattan_distance(curr_state[ k ],i);
    swap(curr_state[i],curr_state[k]);
if(dfs(depth+1,cost+d,i,k))
return true;
swap(curr_state[i],curr_state[k]);
}
return false;
}




int IDA_Star(int kings_pos) {
lim = h1();
int h = h1();
while (true) {
nlim = inf;
if (dfs(0, h,-1,kings_pos))
return result;
if (nlim == inf)
return -1;

lim = nlim;
}
}

int main()
{

int p1,p2;
int set_no = 1;
while(cin>>n && n){
int kings_pos;
for(int i=1;i<=n;++i)
{

cin>>curr_state[i];
if(curr_state[i] == 1)
kings_pos = i;
}
cout<<"Set "<<set_no++<<":"<<endl;
cout<<IDA_Star(kings_pos)<<endl;

}


}
int manhattan_distance(int p1,int p2)
{
--p1;
--p2;
int res = abs(p1%4 - p2%4) + abs(p1/4 - p2/4);
if((p1%4 == 0 && p2%4 == 3)||(p2%4 == 0 && p1%4 == 3))
res-=2;
return res;
}
