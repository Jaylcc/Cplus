#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;
#define Min(a,b) (a<b?a:b)

	/**
	 *	求左部分中的最大值减去右部分最大值的绝对值
	 *	vec: 输入数组
     *  len vec的长度
	 *	返回：左部分中的最大值减去右部分最大值的绝对值
	 */
int GetWinValue(vector<int> arr, int len) {
	if(len<=0) return 0;
	vector<int> sum(arr);
	vector<vector<int> > dp(len, vector<int> (len,0));//?
	for(int i=0;i<len;i++)
	{
		if(i>0) sum[i]+=sum[i-1];//sum每个元素是前面所有（含自身）元素之和
		dp[i][i]=arr[i];
	}
	for(int L=1;L<len;L++)
		for(int i=0;i+L<len;i++)//dp[i][j],i确定左界限，j确定右界限
		{
			int j=i+L;
			dp[i][j]=sum[j]-sum[i]+arr[i]-Min(dp[i+1][j],dp[i][j-1]);//
		}
		return sum[len-1]-Min(dp[0][len-1], sum[len-1]-dp[0][len-1]);
}
void main()
{
	int a[]={8,7,5,3};
	size_t n=sizeof(a)/sizeof(int);
	vector<int> v(a,a+n);
	cout<<GetWinValue(v,n)<<endl;
}