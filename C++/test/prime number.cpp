#include<iostream>
using namespace std;
//�˳�����Ա��һλ��Ϊ�µļ�����ʼ
struct PERSON
{
	int num;
	PERSON*pNext;
};
void PerSurvive(int N)
{
	PERSON*phead=(PERSON*)malloc(sizeof(PERSON));//ͷָ��
	PERSON*p1,*p2,*p3;
	//��ʼ����
	p1=phead;
	for (int i=1;i<=N;i++)
	{
		p2=(PERSON*)malloc(sizeof(PERSON));
		p2->num=i;
		p1->pNext=p2;
		p1=p2;
	}
	p1=phead->pNext;//����headû�д��numֵ������p1=phead->pNext;�ͷ�p1���ڴ棬��ʱp1��Ϊ1����Ա
	free(phead);
	phead=p1;//phead���1��
	p2->pNext=phead;//�γɱջ���

	while (p1->pNext!=p1)//ֱ������ֻ��һ��Ԫ��ʱ����ѭ��
	{
		p2=p1->pNext;
		p3=p2->pNext;
		p2->pNext=p3->pNext;//��p1->next->next�ͷŵ�
		cout<<p3->num<<"�ų���"<<endl;		
		free(p3);
		p1=p2->pNext;
	}
	cout<<p1->num<<"���ջ�ʤ"<<endl;
	free(p1);
}

void main()
{
	PerSurvive(10);
}
