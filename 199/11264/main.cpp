#include <iostream>

using namespace std;


typedef long long int ll;

ll A[1002];
ll withdraw(int x,int cnt,int n)
{
	if(x == 0) return cnt;
	if(x<A[n])
		return withdraw(x%A[n],cnt,n-1);
	else
		return withdraw(x%A[n],cnt+1,n-1);

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	
	
		int n;
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>A[i];
		int sum = 0,max = 0;
		
		for(int i=0;i<n;++i)
		{
			int x = withdraw(sum+A[i],0,n-1);
			if(x>max)
			{
				max = x;
				sum+=A[i];
			}
		
		}
		cout<<max<<endl;
		
		
    
    }
    
    
    
}
