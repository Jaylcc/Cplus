

#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;


int min(vector<int> a, vector<int> b)
{
	return abs(a[0] - b[0]) < abs(a[1] - b[1]) ? abs(a[0] - b[0]) : abs(a[1] - b[1]);
}
int dis(vector<vector<int> > a, int s, int e)//first we set s=0,e=len-1
{
	int low = min(a[s], a[e]);
	if(s==e)
		return 0;
	else
	{
		for (int i = s + 1; i < e; i++)
		{
			if ((dis(a, s, i) + dis(a, i, e)) < low)
				low = dis(a, s, i) + dis(a, i, e);
		}
		return low;
	}
}
void main()
{
	int num;
	cin >> num;
	vector<int> c(2, 0);
	vector<vector<int> > v;
	for (int i = 0; i < num; i++)
	{
		cin >>c[0]>>c[1];
		v.push_back(c);
	}
	cout<<dis(v, 0, num-1)<<endl;
}