#include <iostream>

using namespace std;

int main()
{
   int tot,m;
   cin>>tot>>m;
   for(int i=0;i<200000;++i)
   {
       if(tot%m == 0)
       {
        cout<<"Yes";
        return 0;
       }
       tot+=(tot%m);


   }
   cout<<"No";
}
