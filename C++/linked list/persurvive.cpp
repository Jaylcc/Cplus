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
		p2=(per*)malloc(sizeof(per));//分配内存空间，事实上这里的sizeof(per)长度为8
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
		cout<<p3->num<<"号出局！"<<endl;
		p2->pnext=p3->pnext;
		free(p3);
		p1=p2->pnext;//由下一位开始数
	}
	cout<<p1->num<<"win!"<<endl;
	free(p1);

}
void main()
{
	persurvive(10);
}