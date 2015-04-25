#include <stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;
#include<math.h>
#include<sstream>
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		int len = numbers.size();
		if (len != 0)
		{
			string s="";
			vector<string> strs(len,"");
			stringstream ss;
			for (int i = 0; i < len; ++i)
			{
				ss << numbers[i];
				ss >> strs[i];
				ss.clear();
			}
			quicksort(strs, 0, len - 1);
			for (int i = 0; i < len; ++i)
			{
				s += strs[i];
			}
			return s;
		}
		return " ";
	}
	void quicksort(vector<string> &v, int left, int right)
	{
		if (left < right)
		{
			string key = v[left];
			int low = left;
			int high = right;
			while (low < high)
			{
				while (low < high &&small(key, v[high]))
					high--;
				v[low] = v[high];
				while (low < high&&small(v[low], key))
					low++;
				v[high] = v[low];
			}
			v[low] = key;
			quicksort(v, left, low - 1);
			quicksort(v, low + 1, right);
		}
	}
	bool small(string x, string y)//x<y, true;x>y,false
	{	
		char tx = x[0];
		char ty = y[0];
		if (tx==ty)
		{
			int nx = x.size();
			int ny = y.size();
			if (nx>ny)
			{
				string temp(x.begin()+ny,x.end());
				return small(temp,y);
			}
			else
			{
				string temp(y.begin()+nx,y.end());
				return small(x, temp);
			}
		}
		return tx < ty ? true : false;
	}
};

void main(){
	Solution s1;
	string s;
	int a[5] = { 3, 32, 321, 45, 4 };
	vector<int> v(a, a + 5);
	s = s1.PrintMinNumber(v);
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] ;
	}
	cout << endl;
	system("pause");
}
