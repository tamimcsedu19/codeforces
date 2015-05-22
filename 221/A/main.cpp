#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int pivot;
    for(pivot=0;s[pivot]!='^';++pivot);
    long long int leftMass=0,rightMass=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!='=')
        {
            if(i<pivot)
                leftMass+=(pivot-i)*(s[i]-48);

            else if(i>pivot)
                rightMass+=(i-pivot)*(s[i]-48);
        }

    }
    if(leftMass>rightMass)
        cout<<"left"<<endl;
    else if(leftMass<rightMass)
        cout<<"right"<<endl;
    else
        cout<<"balance"<<endl;

}
