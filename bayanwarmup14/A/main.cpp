#include <iostream>

using namespace std;
string bus[50];
int main()
{
    int k;
    cin>>k;
    for(int i=1;i<=6;++i)
        bus[i].clear();
    bus[1] = "+------------------------+";
    int cnt = 0;
    for(int i=0;i<=25;++i)
        for(int j=2;j<=5;++j)
        {
            if(i%2 == 0)
            {
                if(i == 0)
                    bus[j].append("|");
                else if(i==24 && j==2)
                    bus[j].append("D");
                else
                    bus[j].append(".");
            }
            else
            {
                if(j == 4 && i== 1 && cnt<k)
                {
                    bus[j].append("O");
                    ++cnt;
                    continue;
                }
                if(j==4)
                {
                     bus[j].append(".");
                     continue;
                }
                if(i==25 || i==23)
                    bus[j].append("|");
                else if(cnt<k)
                    {
                        bus[j].append("O");
                        ++cnt;

                    }
                else
                    bus[j].append("#");


            }

        }
        bus[4][25] = '|';
        bus[2].append(")");
        bus[5].append(")");
        bus[6] = "+------------------------+";
        for(int i=1;i<=6;++i)
            cout<<bus[i]<<"\n";
        cout<<"\n";

}
