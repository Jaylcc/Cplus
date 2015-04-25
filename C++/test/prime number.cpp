#include<iostream>
using namespace std;
//退出的人员后一位作为新的计数开始
struct PERSON
{
	int num;
	PERSON*pNext;
};
void PerSurvive(int N)
{
	PERSON*phead=(PERSON*)malloc(sizeof(PERSON));//头指针
	PERSON*p1,*p2,*p3;
	//初始化，
	p1=phead;
	for (int i=1;i<=N;i++)
	{
		p2=(PERSON*)malloc(sizeof(PERSON));
		p2->num=i;
		p1->pNext=p2;
		p1=p2;
	}
	p1=phead->pNext;//由于head没有存放num值，故令p1=phead->pNext;释放p1的内存，此时p1成为1号人员
	free(phead);
	phead=p1;//phead变成1号
	p2->pNext=phead;//形成闭环链

	while (p1->pNext!=p1)//直到链表只有一个元素时结束循环
	{
		p2=p1->pNext;
		p3=p2->pNext;
		p2->pNext=p3->pNext;//将p1->next->next释放掉
		cout<<p3->num<<"号出局"<<endl;		
		free(p3);
		p1=p2->pNext;
	}
	cout<<p1->num<<"最终获胜"<<endl;
	free(p1);
}

void main()
{
	PerSurvive(10);
}
