#include <iostream>
using namespace std;
struct per
{
	int num;
	per *pnext;
};
void persurvive(int N)
{
	per *p1,*p2,*p3;
	per *phead=(per*)malloc(sizeof(per));//head pointer at now
	p1=phead;
	p1->num=1;
	for(int i=2;i<=N;i++)
	{
		p2=(per*)malloc(sizeof(per));//�����ڴ�ռ䣬��ʵ�������sizeof(per)����Ϊ8
		p2->num=i;
		p1->pnext=p2;
		p1=p2;
	}
	p2->pnext=phead;
	p1=phead;
	while(p1->pnext!=p1)
	{
		p2=p1->pnext;
		p3=p2->pnext;
		cout<<p3->num<<"�ų��֣�"<<endl;
		p2->pnext=p3->pnext;
		free(p3);
		p1=p2->pnext;//����һλ��ʼ��
	}
	cout<<p1->num<<"win!"<<endl;
	free(p1);

}
void main()
{
	persurvive(10);
}