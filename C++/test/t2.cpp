#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

static int x = 0;
static int y = 0;
static int z = 0;
bool judge(int cr, int cy, int cb)
{
		int samenum = 0;
		int a, b, c;
		a = abs(cr - cy);
		b = abs(cr - cb);
		c = abs(cb - cy);	
		int numin[3] = {a, b, c};
		
		for (int  i = 0; i < 3; i++){
			if( (numin[i] == x) || (numin[i] == y) || (numin[i] == z))
				samenum ++;
		}
			
		if(samenum == 3) {
			return true;
		} else {
			return false;
		}	
}
void main()
{
	int cr=0;
	int cy=0;
	int cb=0;
	int max=0;
	cin>>x>>y>>z;
	string str;
	char temp;
	cin.get();
	while((temp=cin.get())!='\n')
	{
		str+=temp;
	}
	const int len =str.length();
	char* incol = new char[len];
	for(int i = 0;i<len;i++)   //将字符串保存到字符数组中 
	{
		incol[i]=str[i];
	}
	for(i=0;i<len;i++)
	{
		if (incol[i] == 'R'){
			cr += 1;
		}
		if (incol[i] == 'B'){
			cy += 1;
		}
		if (incol[i] == 'Y'){
			cb += 1;
		}	
		if( judge(cr, cy, cb)&&(cr+cy+cb)>max){
			max=cr+cy+cb;
			cr=0;
			cy=0;
			cb=0;
		}
		if((cr+cy+cb)>max)
			max=cr+cy+cb;
	}
	cout<<max<<endl;
	delete incol;
}