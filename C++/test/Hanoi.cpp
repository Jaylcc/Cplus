	#include <fstream>

	#include <iostream>
	
	using namespace std;
	
	
	void Move(int n,char x,char y)
	
	{
	    cout<<"��"<<n<<"�Ŵ�"<<x<<"Ų����"<<y<<endl;
	}
//n=even��acb;
//n=odd,  abc;
//�м䲽�趼��a->c���м����϶���a->b���м����¶���b->c��
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
	    cout<<"������7�㺺ŵ���Ľⷨ:"<<endl;
	    Hannoi(7,'a','b','c');
	    cout<<"�����ϣ�"<<endl;
	    return 0;
	}
