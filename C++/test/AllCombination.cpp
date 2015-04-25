#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

void Combination(char *str)
{
	if(str == NULL)
		return ;
	int len = strlen(str);
	int n = 1<<len;
	for(int i=1;i<n;i++)    //从 1 循环到 2^len -1
	{
		int temp = i;
		for(int j=0;j<len;j++)
		{
			if(temp & (1<<j))   //1<<j,分别让各个位上为1，如：001,010,100。
//temp与该值按位与，为1的输出值
			{
				cout<<*(str+j);
			}
		}
		cout<<endl;
	}
}
void main()
{
	char str[] = "abc";
	Combination(str);
}