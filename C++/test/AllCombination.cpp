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
	for(int i=1;i<n;i++)    //�� 1 ѭ���� 2^len -1
	{
		int temp = i;
		for(int j=0;j<len;j++)
		{
			if(temp & (1<<j))   //1<<j,�ֱ��ø���λ��Ϊ1���磺001,010,100��
//temp���ֵ��λ�룬Ϊ1�����ֵ
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