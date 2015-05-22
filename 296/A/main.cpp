#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
   ll cnt = 0;
   ll a,b; cin>>a>>b;
   while(a!=b)
   {
        if(a<b) swap(a,b);
        cnt+=(a/b);
        if(a%b == 0)
            break;
        a = a%b;


   }
   cout<<cnt;


}
