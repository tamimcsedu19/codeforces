#include <iostream>
#include <algorithm>
using namespace std;
bool binary(int *A,int low,int high,int val)
{
	if(low == high)
		if(A[low] == val)
			return 1;
	else
		return 0;
	int mid = (low+high)/2;
	if(A[mid]==val)
		return 1;
	else if(A[mid]>val)
		return binary(A,low,mid,val);
	else
		return binary(A,mid+1,high,val);
}
int main()
{
    int n;
    cin>>n;
    int a = n/3, b = n/3 + n/3 ;
    int A[n];
    for(int i=0;i<n;++i)
		cin>>A[i];
	sort(A,A+n);
	bool flag = 1;
	if(A[a] == A[a-1])
		flag = 0;
	else if(A[b] == A[b-1])
		flag = 0;
	for(int i=0;i<a;++i)
	{
		int divide = 0;
		for(int j=a;j<b;++j)
		{
			if(A[j]%A[i] == 0)
			{
				divide = 1;
				break;
			}
		}
		if(!divide)
		{
			flag = 0;
			break;
		}
	}
	
	for(int i=a;i<b;++i)
	{
		int divide = 0;
		for(int j=b;j<n;++j)
		{
			if(A[j]%A[i] == 0)
			{
				divide = 1;
				break;
			}
		}
		if(!divide)
		{
			flag = 0;
			break;
		}
	
	
	}
	if(flag)
	{
		for(int i=0,j=a,k=b;i<a;++i,++j,++k)
			cout<<A[i]<<" "<<A[j]<<" "<<A[k]<<endl;
	
	}
	else
		cout<<-1<<endl;
	
	
	
	
	
}
