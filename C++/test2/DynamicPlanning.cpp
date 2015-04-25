#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;
void main()
{
	int a[]={1,2,5};
	int n=sizeof(a)/sizeof(int);
	cout<<n<<endl;
	vector<int> v(a,a+n);
	vector< vector<int> > dp;
	//vector<vector< int> > unit;
}