#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		int n2 = n / 2,n1,sum=0;
		for (int i = 0; i < n2; ++i)
		{
			n1 = n - i * 2;
			sum +=arrange(n1, i);
		}
		return sum;
	}
	int arrange(int &m, int &n)
	{
		if (m>n)
			return m + 1 + fac(m) / (fac(n)*fac(m - n));
		else
			return n + 1 + fac(n) / (fac(m)*fac(n - m));
	}
	int fac(int x)
	{
		register int i, f = 1;  //定义寄存器变量  
		for (i = 2; i <= x; i++)
			f *= i;
		return f;
	}
};

int main()
{
	Solution s;
	int n = 4;
	cout << s.climbStairs(n) << endl;

	system("pause");
	return 0;
}