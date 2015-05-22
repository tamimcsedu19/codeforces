#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<int,int> wt;
int main()
{
    wt['q'] = 9;
    wt['r'] = 5;
    wt['b'] = 3;
    wt['k'] = 3;
    wt['p'] = 1;
    int whiteCnt = 0,blackCnt = 0;
    for(int i=0;i<8;++i)
        for(int j=0;j<8;++j)
        {
            char c; cin>>c;
            if(isupper(c))
            {
                whiteCnt+=(wt[tolower(c)]);
            }
            else if(islower(c))
            {
                blackCnt+=wt[c];
            }

        }
    if(whiteCnt > blackCnt)
        cout<<"White";
    else if(whiteCnt == blackCnt)
        cout<<"Draw";
    else
        cout<<"Black";

}

