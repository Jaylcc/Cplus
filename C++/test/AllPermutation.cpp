#include<iostream>
#include<stdlib.h>
using namespace std;
//长度可变，以4为例
static int len=4;
void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void Paixu(int a[],int i)
{
	if(i==len-1)
	{
		for(int j=0;j<len;j++)
		{
			cout<<a[j]<<' ';
		}
		cout<<endl;
	}
	else
	{
		Paixu(a,i+1);
		for(int p=i+1;p<len;p++)
		{
			if(a[i]!=a[p])
			{
				swap(a,p,i);
				Paixu(a,i+1);
				swap(a,p,i);
			}
		}
	}
}
void main()
{
	int a[4]={1,1,1,1};
	Paixu(a,0);
}