#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int  *count = new int[t];
	memset(count,0,sizeof(count)*t);
	for (int it = 0; it < t; ++it)
	{
		string s;
		cin >> s;
		int n = s.size();
		int i = 0, j = n - 1;
		while (i <j)
		{
			while (s[i] == '0' && i < j)
				i++;
			while (s[j] == '1'&&j>i)
				j--;
			if (i != j)
			{
				++count[it];
				i++;
				j--;
			}	
		}
	}
	for (int i = 0; i < t; i++)
	{
		cout << count[i] << endl;
	}
	system("pause");
	return 0;
}