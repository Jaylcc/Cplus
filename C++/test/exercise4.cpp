#include<vector>
#include<iostream>
using namespace std;
void main()
{
	vector<int> A;
	vector<int> B(10,100);
	vector<int> C(B.begin(),B.end());
	vector<int> d(B);
	cout<<C.size()<<endl;
	vector<int> F(10); //����һ����10��Ԫ�ص�����
    for (int i = 0; i < 10; i++)
        {
			F[i] = i;
        }
	vector<int>::reverse_iterator be=F.rbegin();
	cout<<*be<<endl;
}