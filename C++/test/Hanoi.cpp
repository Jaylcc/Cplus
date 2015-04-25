	#include <fstream>

	#include <iostream>
	
	using namespace std;
	
	
	void Move(int n,char x,char y)
	
	{
	    cout<<"把"<<n<<"号从"<<x<<"挪动到"<<y<<endl;
	}
//n=even，acb;
//n=odd,  abc;
//中间步骤都是a->c，中间以上都是a->b，中间以下都是b->c。
	void Hannoi(int n,char a,char b,char c)
	{
	    if(n==1)
	        Move(1,a,c);
	    else
	    {
	        Hannoi(n-1,a,c,b);
	        Move(n,a,c);
	        Hannoi(n-1,b,a,c);
	    }
	}
	
	int main()
	{
	    cout<<"以下是7层汉诺塔的解法:"<<endl;
	    Hannoi(7,'a','b','c');
	    cout<<"输出完毕！"<<endl;
	    return 0;
	}
