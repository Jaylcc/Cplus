#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;
#define Min(a,b) (a<b?a:b)

	/**
	 *	���󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ
	 *	vec: ��������
     *  len vec�ĳ���
	 *	���أ��󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ
	 */
int GetWinValue(vector<int> arr, int len) {
	if(len<=0) return 0;
	vector<int> sum(arr);
	vector<vector<int> > dp(len, vector<int> (len,0));//?
	for(int i=0;i<len;i++)
	{
		if(i>0) sum[i]+=sum[i-1];//sumÿ��Ԫ����ǰ�����У�������Ԫ��֮��
		dp[i][i]=arr[i];
	}
	for(int L=1;L<len;L++)
		for(int i=0;i+L<len;i++)//dp[i][j],iȷ������ޣ�jȷ���ҽ���
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