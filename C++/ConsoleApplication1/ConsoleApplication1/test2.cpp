#include<iostream>
#include<string>
using namespace std;
string s;//输入值
bool moveR(char c)
{
	if (c == '3' || c == '6' || c == '9' || c == '0')
		return false;
	else
		return true;
}
bool moveD(char c)
{
	if (c == '7' || c == '0' || c == '9')
		return false;
	else
		return true;
}
bool cmp(string s1, string s2)
{
	if (s1.length() > s2.length())
		return true;
	else if (s1.length() < s2.length())
		return false;
	else
	{
		const char *p1 = s1.data(), *p2 = s2.data();
		return strcmp(p1, p2)<0 ? false : true;
	}
}
string bigNum(string s1, string s2)
{
	if (cmp(s1, s2))
		return s1;
	else 
		return s2;
}
string maxNum(char c,string ss)//s为输入值
{
	string s1 = ss + c;
	char c1 = c + 3;
	if (c1 == '8')
		c1 = '0';
	if (cmp(s, s1))
	{
		if (moveR(c) && moveD(c))
		{
			return bigNum(bigNum(c + maxNum(c + 1, s1), c + maxNum(c1, s1)), bigNum(maxNum(c + 1, ss), maxNum(c1, ss)));
		}	
		else if (moveR(c))
			return bigNum(c + maxNum(c + 1, s1), maxNum(c + 1, ss));
		else if (moveD(c))
			return bigNum(c + maxNum(c1, s1), maxNum(c1, ss));
	}
	return "";
}

int main()
{
	string smax="1";
	cin >> s;
	if (s == "0")
		cout << s << endl;
	else
	{
		char sp;
		for (sp = '1'; sp <= '9'; ++sp)
		{
			if (cmp(maxNum(sp, ""), smax))
				smax = maxNum(sp, "");
		}
		cout << smax << endl;
	}

	system("pause");
	return 0;
}