#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int x1,y1,x2,y2;
   cin>>x1>>y1>>x2>>y2;
   if(y1 == y2)
   {
    int diff = abs(x1-x2);
    if(y1+diff <=1000)
    {
        cout<<x1<<" "<<y1+diff<<" "<<x2<<" "<<y2+diff;
        return 0;
    }
    else if(y1-diff >= -1000)
    {
        cout<<x1<<" "<<y1-diff<<" "<<x2<<" "<<y2-diff;
        return 0;
    }


   }
   else if(x1 == x2)
   {
    int diff = abs(y1-y2);
    if(x1+diff <=1000)
    {
        cout<<x1+diff<<" "<<y1<<" "<<x2+diff<<" "<<y2;
        return 0;
    }
    else if(x1-diff >= -1000)
    {
        cout<<x1-diff<<" "<<y1<<" "<<x2-diff<<" "<<y2;
        return 0;
    }

   }
   else if(abs(x1-x2) == abs(y1-y2))
   {
    cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
    return 0;

   }
   cout<<-1<<endl;


}
